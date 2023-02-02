#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include "svg.h"

/* ---------------------------------------------------------------------- *
 * begin common part
 * ---------------------------------------------------------------------- */

unsigned int utf8(unsigned char *s) {
    unsigned int c = s[0];
    if ((c & 0x80) == 0) { // 0xxx xxxx
        return c;
    }
    if ((c & 0xc0) != 0xc0) { // 10xx xxxx
	// not UTF-8 or not first byte
	//        printf("10xx xxxx\n");
        return c;
    }
    // (c & 0xc0) == 0xc0
    if ((c & 0x20) == 0) { // 110y yyyx 10xx xxxx
        unsigned int d = s[1] & 0x3f;
	//        printf("110y yyyx 10xx xxxx\n");
	return (c & 0x1f) << 6  | d ;
    }
    if ((c & 0x10) == 0) { // 1110 yyyy 10yx xxxx 10xx xxxx
        unsigned int d = s[1] & 0x3f, e = s[2] & 0x3f;
	//        printf("1110 yyyy 10yx xxxx 10xx xxxx\n");
	return (c & 0xf) << 12 | d  << 6 | e;
    }
    if ((c & 0x08) == 0) { // 1111 0yyy 10yy xxxx 10xx xxxx 10xx xxxx
        unsigned int d = s[1] & 0x3f, e = s[2] & 0x3f, f = s[3] & 0x3f;
	//        printf("1111 0yyy 10yy xxxx 10xx xxxx 10xx xxxx\n");
	return (c & 0x7) << 18 | d << 12 | e << 6 | f;
    }
    if ((c & 0x04) == 0) { // 1111 10yy 10yy yxxx 10xx xxxx 10xx xxxx 10xx xxxx
        unsigned int d = s[1] & 0x3f, e = s[2] & 0x3f, f = s[3] & 0x3f, g = s[4] & 0x3f;
	//        printf("1111 10yy 10yy yxxx 10xx xxxx 10xx xxxx 10xx xxxx\n");
	return (c & 0x3) << 24 | d << 18 | e << 12 | f << 6 | g;
    }
    if ((c & 0x02) == 0) { // 1111 110y 10yy yyxx 10xx xxxx 10xx xxxx 10xx xxxx 10xx xxxx
        unsigned int d = s[1] & 0x3f, e = s[2] & 0x3f, f = s[3] & 0x3f, g = s[4] & 0x3f, h = s[5] & 0x3f;
	//        printf("1111 110y 10yy yyxx 10xx xxxx 10xx xxxx 10xx xxxx 10xx xxxx\n");
	return (c & 0x1) << 30 | d << 24 | e << 18 | f << 12 | g << 6 | h;
    }
    //    printf("1111 111x\n");
    return c; // 0xFE or 0xFF
}

double bound1(double d) {
    if (d < 0) d = 0.0;
    if (d > 1) d = 1.0;
    return d;
}

unsigned int bound255(int i) {
    if (i < 0) i = 0;
    if (i > 255) i = 255;
    return i;
}

void randomSeed(unsigned int seed) {
    srand(seed);
}

void randomizeByTime(void) {
    srand((unsigned int)time(NULL));
}

double randomInRange(double min, double max) {
    int r = rand();
    return (max - min) * r / RAND_MAX + min;
}

double radians(double deg) {
    return deg / 180 * PI;
}

static double __strokeWeight = 1;

void strokeWeight(double arg) {
    __strokeWeight = arg;
}

static char __stroke[8] = "none";

void stroke(unsigned int arg) {
    if (arg > 0xffffff) arg = 0xffffff;
    sprintf(__stroke, "#%06x", arg);
}

void noStroke(void) {
    sprintf(__stroke, "none");
}

static double __strokeOpacity = 1;

void strokeOpacity(double o) {
    __strokeOpacity = bound1(o);
}

static char __fill[8]   = "#000000";

void fill(unsigned int arg) {
    if (arg > 0xffffff) arg = 0xffffff;
    sprintf(__fill, "#%06x", arg);
}

void noFill(void) {
    sprintf(__fill, "none");
}

static double __fillOpacity = 1;

void fillOpacity(double o) {
    __fillOpacity = bound1(o);
}

static const char* __fontFamily = "MS-Mincho";
/* char * __fontFamily = "Times New Roman"; */

static double __fontSize = 12;

void textFont(const char* font, double size) {
    __fontFamily = font;
    __fontSize = size;
}


unsigned int rgb255(double r, double g, double b) {
    unsigned int r1 = bound255((int)r),
                 g1 = bound255((int)g),
                 b1 = bound255((int)b);
    return (r1 * 0x10000) + (g1 * 0x100) + b1;
}

unsigned int rgb100(double r, double g, double b) {
    return rgb255(r * 2.55, g * 2.55, b * 2.55);
}

unsigned int rgb1(double r, double g, double b) {
    return rgb255(r * 255, g * 255, b * 255);
}

unsigned int hsb1(double h, double s, double v) {
    double r = 0, g = 0, b = 0;

    h *= 360;
    while (h >= 360) h -= 360;
    while (h < 0)   h += 360;

    s = bound1(s);
    if (s == 0) {
        r = g = b = v;
    } else {
        int H, h1;
        double f, p, q, t;

        v = bound1(v);

        H = (int)h;
        h1 = H / 60;

        f = h / 60 - h1;
        p = v * (1 - s);
        q = v * (1 - f * s);
        t = v * (1 - (1 - f) * s);

        switch (h1) {
        case 0: r = v; g = t; b = p; break;
        case 1: r = q; g = v; b = p; break;
        case 2: r = p; g = v; b = t; break;
        case 3: r = p; g = q; b = v; break;
        case 4: r = t; g = p; b = v; break;
        case 5: r = v; g = p; b = q; break;
        }
    }
    return rgb1(r, g, b);
}

unsigned int hsb100(double h, double s, double v) {
    return hsb1(h / 100, s / 100, v / 100);
}

unsigned int hsb360(double h, double s, double v) {
    return hsb1(h / 360, s / 100, v / 100);
}

unsigned int hsb255(double h, double s, double v) {
    return hsb1(h / 255, s / 255, v / 255);
}

unsigned int hsl1(double h, double s, double l) {
    if (l == 0) {
        /* max = min = 0 */
        return hsb1(h, 0, 0);
    } else if (l <= 0.5) {
        double diff = s * l;
        double max  = l + diff;
        double min  = l - diff;
        return hsb1(h, 1 - min / max, max);
    } else {
        double diff = s * (1 - l);
        double max  = l + diff;
        double min  = l - diff;
        return hsb1(h, 1 - min / max, max);
    }
}

unsigned int hsl100(double h, double s, double l) {
    return hsl1(h / 100, s / 100, l / 100);
}

unsigned int hsl360(double h, double s, double l) {
    return hsl1(h / 360, s / 100, l / 100);
}

unsigned int hsl255(double h, double s, double l) {
    return hsb1(h / 255, s / 255, l / 255);
}

unsigned int bw255(double v) {
    return rgb255(v, v, v);
}

unsigned int bw100(double v) {
    return bw255(v * 2.55);
}

unsigned int bw1(double v) {
    return bw255(v * 255);
}

double cos360(double deg) {
    return cos(radians(deg));
}

double sin360(double deg) {
    return sin(radians(deg));
}

double* rgb2hsb360(unsigned int rgb, double* ret) {
    unsigned int b = rgb % 0x100;
    unsigned int g = rgb / 0x100 % 0x100;
    unsigned int r = rgb / 0x10000 % 0x100;
    unsigned int max, min, sub, angle;

    if (r >= g) { // ? r ? g ?
        if (g >= b) { // r g b
            max = r; min = b; sub = g - b; angle = 0;
        } else if (b >= r) { // b r g
            max = b; min = g; sub = r - g; angle = 240;
        } else { // r b g
            max = r; min = g; sub = g - b; angle = 0;
        }
    } else { // ? g ? r ?
        if (r >= b) { // g r b
            max = g; min = b; sub = b - r; angle = 120;
        } else if (b >= g) { // b g r
            max = b; min = r; sub = r - g; angle = 240;
        } else { // g b r
            max = g; min = r; sub = b - r; angle = 120;
        }
    }

    ret[0] = 60 * ((double)sub / (max - min)) + angle;
    if (ret[0] < 0) ret[0] += 360;
    ret[1] = 100.0 * (max - min) / max;
    ret[2] = max / 255.0 * 100;
    return ret;
}

unsigned int rotateH360(unsigned int color, double a) {
    double hsb[3];
    rgb2hsb360(color, hsb);
    hsb[0] += a;
    return hsb360(hsb[0], hsb[1], hsb[2]);
}

unsigned int rotateH(unsigned int color) {
    return rotateH360(color, PHYLLOTAXIS360);
}

unsigned int addS100(unsigned int color, double a) {
    double hsb[3];
    rgb2hsb360(color, hsb);
    hsb[1] += a;
    return hsb360(hsb[0], hsb[1], hsb[2]);
}

unsigned int scaleS(unsigned int color, double a) {
    double hsb[3];
    rgb2hsb360(color, hsb);
    hsb[1] *= a;
    return hsb360(hsb[0], hsb[1], hsb[2]);
}

unsigned int addB100(unsigned int color, double a) {
    double hsb[3];
    rgb2hsb360(color, hsb);
    hsb[2] += a;
    return hsb360(hsb[0], hsb[1], hsb[2]);
}

unsigned int scaleB(unsigned int color, double a) {
    double hsb[3];
    rgb2hsb360(color, hsb);
    hsb[2] *= a;
    return hsb360(hsb[0], hsb[1], hsb[2]);
}

/* ---------------------------------------------------------------------- *
 * end common part
 * ---------------------------------------------------------------------- */

static double width=297, height=210;

static int __landscape = 1;

#define __leftMargin 15
#define __rightMargin 30
#define __topMargin 15
#define __bottomMargin 15

static int __currentLeftMargin = __leftMargin,
    __currentRightMargin = __rightMargin;
static int __currentTopMargin = __topMargin,
    __currentBottomMargin = __bottomMargin;

void setPageSize(double w, double h) {
    width = w; height = h;
}

double centerX() {
    return width / 2;
}

double centerY() {
    return height / 2;
}

double pageWidth() {
    return width;
}

double pageHeight() {
    return height;
}

void a4Landscape(void) {
    width = 297;  height = 210;
    __landscape = 1;
    __currentLeftMargin = __leftMargin;
    __currentRightMargin = __rightMargin;
    __currentTopMargin = __topMargin;
    __currentBottomMargin = __bottomMargin;
}

void a4Portrait(void) {
    width = 210;  height = 297;
    __landscape = 0;
    __currentTopMargin = __rightMargin;
    __currentBottomMargin = __leftMargin;
    __currentLeftMargin = __topMargin;
    __currentRightMargin = __bottomMargin;
}

double getWidth(void) {
    return width;
}

double getHeight(void) {
    return height;
}

static int __gDepth = 0;
static int __gSP = 0;

void startEnc(const char* enc) {
    printf("<?xml version=\"1.0\" encoding=\"%s\"?>\n", enc);
    printf("<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n");
    printf("  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n");
    printf("<svg version=\"1.1\" width=\"%.2fmm\" height=\"%.2fmm\"\n", width, height);
    printf("  viewBox=\"0 0 %.2f %.2f\"\n", width, height);
    printf("  preserveAspectRatio=\"xMidYMid\"\n");
    printf("  fill-rule=\"evenodd\"\n");
    printf("  xmlns=\"http://www.w3.org/2000/svg\"\n");
    printf("  xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n");
    randomizeByTime();
    __gDepth = 0;
    __gSP = 0;
}

void start(void) {
    /*
      the default encoding
    */
    /*    startEnc("Shift_JIS"); */
    startEnc("utf-8");
}


#define GSTACK_SIZE 1024

static int __gStack[GSTACK_SIZE] = { 0 };

static void __pushGStack(void) {
    if (__gSP >= GSTACK_SIZE) {
        fprintf(stderr, "Stack Overflow!\n");
        return;
    }
    __gStack[__gSP++] = __gDepth;
}

static int __popGStack(void) {
    if (__gSP <= 0) {
        fprintf(stderr, "Stack Underflow!\n");
        return 0;
    }
    return __gStack[--__gSP];
}

void pushMatrix(void) {
    __pushGStack();
}

void popMatrix(void) {
    int tmp = __popGStack();
    while (__gDepth > tmp) {
        __gDepth--;
        printf("</g>\n");
    }
}

void resetMatrix(void) {
    while (__gDepth > 0) {
        __gDepth--;
        printf("</g>\n");
    }
    __gSP = 0;
}

void translate(double x, double y) {
    printf("<g transform=\"translate(%f,%f)\">\n", x, y);
    __gDepth++;
}

void rotate360(double theta) {
    printf("<g transform=\"rotate(%f)\">\n", theta);
    __gDepth++;
}

void rotate(double deg) {
    rotate360(deg * 180 / PI);
}

void scale(double sx, double sy) {
    printf("<g transform=\"scale(%f, %f)\">\n", sx, sy);
    __gDepth++;
}

void line(double x1, double y1, double x2, double y2) {
    printf("<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\"", x1, y1, x2, y2);
    printf("  stroke=\"%s\" stroke-width=\"%f\" stroke-opacity=\"%f\"",
           __stroke, __strokeWeight, __strokeOpacity);
    printf("  stroke-linecap=\"round\" />\n");
}

void rect(double x, double y, double w, double h) {
    printf("<rect width=\"%f\" height=\"%f\"", w, h);
    printf("  x=\"%f\" y=\"%f\"", x, y);
    printf("  stroke=\"%s\" stroke-width=\"%f\" stroke-opacity=\"%f\"", __stroke, __strokeWeight, __strokeOpacity);
    printf("  fill=\"%s\" fill-opacity=\"%f\"", __fill, __fillOpacity);
    printf("  stroke-linecap=\"round\" />\n");
}

void ellipse(double x, double y, double w, double h) {
    printf("<ellipse rx=\"%f\" ry=\"%f\"", w/2, h/2);
    printf("  cx=\"%f\" cy=\"%f\"", x, y);
    printf("  stroke=\"%s\" stroke-width=\"%f\" stroke-opacity=\"%f\"", __stroke, __strokeWeight, __strokeOpacity);
    printf("  fill=\"%s\" fill-opacity=\"%f\" />\n", __fill, __fillOpacity);
}

void triangle(double x1, double y1, double x2, double y2, double x3, double y3) {

    printf("<polygon points=");
    printf("\"%f,%f  %f,%f, %f,%f\"", x1, y1, x2, y2, x3, y3);
    printf("  stroke=\"%s\" stroke-width=\"%f\" stroke-opacity=\"%f\"", __stroke, __strokeWeight, __strokeOpacity);
    printf("  fill=\"%s\" fill-opacity=\"%f\"", __fill, __fillOpacity);
    printf("  stroke-linecap=\"round\" />\n");
}

void quad(double x1, double y1, double x2, double y2,
          double x3, double y3, double x4, double y4) {

    printf("<polygon points=");
    printf("\"%f,%f  %f,%f, %f,%f, %f,%f\"", x1, y1, x2, y2, x3, y3, x4, y4);
    printf("  stroke=\"%s\" stroke-width=\"%f\" stroke-opacity=\"%f\"", __stroke, __strokeWeight, __strokeOpacity);
    printf("  fill=\"%s\" fill-opacity=\"%f\"", __fill, __fillOpacity);
    printf("  stroke-linecap=\"round\" />\n");
}

void quadrilateral(double x1, double y1, double x2, double y2,
                   double x3, double y3, double x4, double y4) {

    printf("<polygon points=");
    printf("\"%f,%f  %f,%f, %f,%f, %f,%f\"", x1, y1, x2, y2, x3, y3, x4, y4);
    printf("  stroke=\"%s\" stroke-width=\"%f\" stroke-opacity=\"%f\"", __stroke, __strokeWeight, __strokeOpacity);
    printf("  fill=\"%s\" fill-opacity=\"%f\"", __fill, __fillOpacity);
    printf("  stroke-linecap=\"round\" />\n");
}

void arc(double x, double y, double w, double h, double start, double stop) {
    double x0, y0, x1, y1;
    int large;

    if (stop < start) {
        double tmp = stop;
        stop = start;
        start = tmp;
    }
    x0 = x + w / 2 * cos(start), y0 = y + h / 2 * sin(start),
        x1 = x + w / 2 * cos(stop), y1 = y + h / 2 * sin(stop);
    large = stop - start > PI;
    printf("<path d=");
    printf("\"M%f,%f A%f,%f", x0, y0, w / 2, h / 2);
    printf(" 0 %d,%d %f,%f\"\n", large, 1, x1, y1);
    printf("  stroke=\"%s\" stroke-width=\"%f\" stroke-opacity=\"%f\"", __stroke, __strokeWeight, __strokeOpacity);
    printf("  fill=\"%s\" fill-opacity=\"%f\"", __fill, __fillOpacity);
    printf("  stroke-linecap=\"round\" />\n");
}

void arc360(double x, double y, double w, double h, double start, double stop) {
    arc(x, y, w, h, radians(start), radians(stop));
}

void bezier(double ax0, double ay0, double cx0, double cy0,
            double cx1, double cy1, double ax1, double ay1) {
    printf("<path d=");
    printf("\"M%f,%f", ax0, ay0);
    printf("  C%f,%f %f,%f %f,%f\"\n", cx0, cy0, cx1, cy1, ax1, ay1);
    printf("  stroke=\"%s\" stroke-width=\"%f\" stroke-opacity=\"%f\"", __stroke, __strokeWeight, __strokeOpacity);
    printf("  fill=\"none\"");
    printf("  stroke-linecap=\"round\" />\n");
}

void vtext(const char* str, double x, double y, va_list list) {
    printf("<text x=\"%f\" y=\"%f\" \n", x, y);
    printf("  font-family=\"%s\" font-size=\"%f\" \n", __fontFamily, __fontSize);
    printf("  stroke=\"%s\" stroke-width=\"%f\" stroke-opacity=\"%f\" \n", __stroke, __strokeWeight, __strokeOpacity);
    printf("  fill=\"%s\" fill-opacity=\"%f\" >\n", __fill, __fillOpacity);
    vprintf(str, list);
    printf("\n");
    printf("</text>\n");
}

void text(const char* str, double x, double y, ...) {
    va_list list;
    va_start(list, y);
    vtext(str, x, y, list);
    va_end(list);
}

static int __first_vertex = 1;

void beginShape(void) {
    printf("<path d=\"");
    __first_vertex = 1;

}

void vertex(double x, double y) {
    if (__first_vertex) {
        printf("M");
        __first_vertex = 0;
    } else {
        printf("L");
    }
    printf("%f,%f ", x, y);
}

void bezierVertex(double cx0, double cy0, double cx1, double cy1, double x1, double y1) {
    printf("C %f,%f %f,%f %f,%f ", cx0, cy0, cx1, cy1, x1, y1);
}

void endShape(int close) {
    if (close) {
        printf("Z\"\n");
    } else {
        printf("\"\n");
    }
    printf("  stroke=\"%s\" stroke-width=\"%f\" stroke-opacity=\"%f\"", __stroke, __strokeWeight, __strokeOpacity);
    printf("  fill=\"%s\" fill-opacity=\"%f\"", __fill, __fillOpacity);
    printf("  stroke-linecap=\"round\" />\n");
}

void image(const char* url, double x, double y, double w, double h) {
    printf("<image x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\"", x, y, w, h);
    printf(" xlink:href=\"%s\" />\n", url);
}

void use(const char* url, double x, double y, double w, double h) {
    printf("<g style=\"stroke:%s;stroke-width:%f;stroke-opacity:%f", __stroke, __strokeWeight, __strokeOpacity);
    printf(";fill:%s;fill-opacity:%f\">\n", __fill, __fillOpacity);
    printf("<use x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\"", x, y, w, h);
    printf(" xlink:href=\"%s\" />\n", url);
    printf("</g>\n");
}

void upperBar(double height) {
    rect(0, 28.5 - height, WIDTH, height);
    /*
        printf("<g style=\"stroke:none;fill:%s;fill-opacity:%f\">\n", __fill, __fillOpacity);
        printf("    <path d=\"M 0,23.5 L 297,23.5 297,28.5 0,28.5 0,23.5 Z\"/>\n");
        printf("</g>\n");
    */
}

void lowerBar(double height) {
    rect(0, 181.5, WIDTH, height);
    /*
        printf("<g style=\"stroke:none;fill:%s;fill-opacity:%f\">\n", __fill, __fillOpacity);
        printf("    <path d=\"M 0,181.5 L 297,181.5 297,186.5 0,186.5 0,181.5 Z\"/>\n");
        printf("</g>\n");
    */
}

void guideBars(double height) {
    upperBar(height);
    lowerBar(height);
}

void rulers(void) {
    int i;
    double tmpW = __strokeWeight;
    char tmpC[8];
    for (i = 0; i < 8; i++) {
        tmpC[i] = __stroke[i];
    }
    strokeWeight(0.2);
    stroke(bw1(0));
    line(0, 28.5, 20, 28.5);
    line(277, 28.5, 297, 28.5);
    line(0, 181.5, 20, 181.5);
    line(277, 181.5, 297, 181.5);
    for (i = 0; i < 8; i++) {
        __stroke[i] = tmpC[i];
    }
    strokeWeight(tmpW);
}

void trimMark(void) {
    double sx = 1, sy = 1;
    double tmpW = __strokeWeight;
    double tmpO = __strokeOpacity;
    double tmpQ = __fillOpacity;
    char tmpC[8];
    char tmpF[8];
    int i;

    strokeWeight(0.5);
    for (i = 0; i < 8; i++) {
        tmpC[i] = __stroke[i];
    }
    stroke(bw1(0));
    strokeOpacity(1);
    if (__landscape) {
        line(10 * sx, 10 * sy, 30 * sx, 10 * sy);
        line(10 * sx, 10 * sy, 10 * sx, 30 * sy);

        line(10 * sx, 200 * sy, 30 * sx, 200 * sy);
        line(10 * sx, 200 * sy, 10 * sx, 180 * sy);

        line(272 * sx, 200 * sy, 252 * sx, 200 * sy);
        line(272 * sx, 200 * sy, 272 * sx, 180 * sy);
    } else {
        line(10 * sx, 10 * sy, 30 * sx, 10 * sy);
        line(10 * sx, 10 * sy, 10 * sx, 30 * sy);

        line(10 * sx, 272 * sy, 10 * sx, 252 * sy);
        line(10 * sx, 272 * sy, 30 * sx, 272 * sy);

        line(200 * sx, 10 * sy, 200 * sx, 30 * sy);
        line(200 * sx, 10 * sy, 180, 10 * sy);
    }

    noStroke();
    for (i = 0; i < 8; i++) {
        tmpF[i] = __fill[i];
    }
    fill(bw1(0));
    fillOpacity(1);
    if (__landscape) {
        ellipse(28 * sx, 182 * sy, 4 * sx, 4 * sy);
    } else {
        ellipse(28 * sx, 28 * sy, 4 * sx, 4 * sy);
    }
    __fillOpacity = tmpQ;
    for (i = 0; i < 8; i++) {
        __fill[i] = tmpF[i];
    }
    __strokeOpacity = tmpO;
    for (i = 0; i < 8; i++) {
        __stroke[i] = tmpC[i];
    }
    strokeWeight(tmpW);
}

static void genericSmilieSymbol(const char* id, char* str) {
    printf("<symbol viewBox=\"0 0 5000 5000\" preserveAspectRatio=\"xMidYMid\" id=\"%s\">\n", id);
    printf("<path d=\"M 2500,0 L 2762,13 3014,49 3257,109 3488,191 3708,294 3914,417 4105,559 4281,719 4441,895 4583,1086 4706,1292 4809,1512 4891,1743 4951,1986 4987,2238 5000,2500 4987,2762 4951,3014 4891,3257 4809,3488 4706,3708 4583,3914 4441,4105 4281,4281 4105,4441 3914,4583 3708,4706 3488,4809 3257,4891 3014,4951 2762,4987 2500,5000 2238,4987 1986,4951 1743,4891 1512,4809 1292,4706 1086,4583 895,4441 719,4281 559,4105 417,3914 294,3708 191,3488 109,3257 49,3014 13,2762 0,2500 13,2238 49,1986 109,1743 191,1512 294,1292 417,1086 559,895 719,719 895,559 1086,417 1292,294 1512,191 1743,109 1986,49 2238,13 2500,0 Z\"/>\n");
    printf("<g style=\"stroke:none;fill:black\">\n");
    printf("<path d=\"M 1690,1469 L 1718,1470 1745,1474 1771,1481 1796,1490 1820,1501 1842,1514 1863,1529 1882,1547 1899,1565 1914,1586 1927,1608 1938,1632 1947,1657 1954,1683 1958,1710 1959,1738 1958,1766 1954,1793 1947,1819 1938,1844 1927,1868 1914,1890 1899,1911 1882,1930 1863,1947 1842,1962 1820,1975 1796,1986 1771,1995 1745,2002 1718,2006 1690,2007 1662,2006 1635,2002 1609,1995 1584,1986 1560,1975 1538,1962 1517,1947 1499,1930 1481,1911 1466,1890 1453,1868 1442,1844 1433,1819 1426,1793 1422,1766 1421,1738 1422,1710 1426,1683 1433,1657 1442,1632 1453,1608 1466,1586 1481,1565 1499,1547 1517,1529 1538,1514 1560,1501 1584,1490 1609,1481 1635,1474 1662,1470 1690,1469 Z\"/>\n");
    printf("</g>\n");
    printf("<g style=\"stroke:none;fill:black\">\n");
    printf("<path d=\"M 3308,1469 L 3336,1470 3363,1474 3389,1481 3414,1490 3438,1501 3460,1514 3481,1529 3500,1547 3517,1565 3532,1586 3545,1608 3556,1632 3565,1657 3572,1683 3576,1710 3577,1738 3576,1766 3572,1793 3565,1819 3556,1844 3545,1868 3532,1890 3517,1911 3500,1930 3481,1947 3460,1962 3438,1975 3414,1986 3389,1995 3363,2002 3336,2006 3308,2007 3280,2006 3253,2002 3227,1995 3202,1986 3178,1975 3156,1962 3135,1947 3117,1930 3099,1911 3084,1890 3071,1868 3060,1844 3051,1819 3044,1793 3040,1766 3039,1738 3040,1710 3044,1683 3051,1657 3060,1632 3071,1608 3084,1586 3099,1565 3117,1547 3135,1529 3156,1514 3178,1501 3202,1490 3227,1481 3253,1474 3280,1470 3308,1469 Z\"/>\n");
    printf("</g>\n");
    printf("<g style=\"stroke:black;stroke-width:200;fill:none\">\n");
    printf("%s\n", str);
    printf("</g>\n");
    printf("</symbol>\n");
}

void smilieSymbol1(const char* id) {
    genericSmilieSymbol(id, "<path style=\"fill:none\" d=\"M 1127,3590 L 1293,3672 1462,3743 1632,3803 1804,3852 1977,3890 2151,3918 2325,3934 2500,3940 2675,3934 2849,3918 3023,3890 3196,3852 3368,3803 3538,3743 3707,3672 3873,3590\"/>");
}

void smilieSymbol2(const char* id) {
    genericSmilieSymbol(id, "<line x1=\"1127\" y1=\"4000\" x2=\"3873\" y2=\"4000\" />");
}

void smilieSymbol3(const char* id) {
    genericSmilieSymbol(id, "<path style=\"fill:none\" d=\"M 1127,4056 L 1293,3974 1462,3903 1632,3843 1804,3794 1977,3756 2151,3728 2325,3712 2500,3707 2675,3712 2849,3728 3023,3756 3196,3794 3368,3843 3538,3903 3707,3974 3873,4056\"/>");
}

void flowerSymbol(const char* id) {
    printf("<symbol viewBox=\"0 0 5000 5000\" preserveAspectRatio=\"xMidYMid\" id=\"%s\">\n", id);
    printf("<path d=\"M 4505,2553 L 4505,2516 4463,2516 4428,2516 4385,2478 4428,2478 4463,2478 4505,2478 4505,2441 4795,2215 4965,1915 5001,1577 4838,1239 4633,976 4300,826 3925,826 3557,938 3515,938 3515,976 3473,976 3473,1013 3473,976 3473,938 3473,938 3473,901 3388,600 3267,375 3062,187 2815,37 2525,0 2192,37 1945,187 1733,375 1612,600 1570,901 1570,938 1570,938 1570,976 1570,1013 1527,976 1485,976 1450,938 1450,938 1075,826 700,826 367,976 162,1239 0,1577 42,1915 205,2215 495,2441 495,2478 537,2478 580,2478 622,2478 580,2516 537,2516 495,2516 495,2553 205,2779 42,3085 0,3386 162,3724 367,3987 700,4137 1075,4174 1450,4062 1450,4024 1485,4024 1527,4024 1570,3987 1570,4024 1570,4062 1570,4062 1570,4099 1612,4400 1733,4625 1945,4813 2192,4963 2525,5001 2815,4963 3062,4813 3267,4625 3388,4400 3473,4099 3473,4062 3473,4062 3473,4024 3473,3987 3473,4024 3515,4024 3515,4024 3557,4062 3925,4174 4300,4137 4633,3987 4838,3724 5001,3386 4965,3085 4795,2779 4505,2553 4505,2553 Z M 2525,1577 L 2192,1614 1902,1765 1655,1952 1527,2215 1485,2516 1527,2779 1655,3048 1902,3235 2192,3386 2525,3423 2815,3386 3098,3235 3352,3048 3473,2779 3557,2516 3473,2215 3352,1952 3098,1765 2815,1614 2525,1577 2525,1577 Z\"/>\n");
    printf("</symbol>\n");
}

void heartSymbol(const char* id) {
    printf("<symbol viewBox=\"0 0 5000 5000\" preserveAspectRatio=\"xMidYMid\" id=\"%s\">\n", id);
    printf("<path d=\"M 2498,5000 L 74,1594 16,1397 11,1373 8,1349 5,1325 3,1300 1,1251 0,1201 2,1154 7,1106 14,1058 23,1011 34,965 48,919 63,874 81,829 101,785 122,741 146,699 171,657 198,616 227,575 257,536 289,498 323,461 358,425 395,390 433,357 473,324 513,293 555,263 598,234 642,207 688,181 734,157 782,135 830,114 879,95 929,77 980,61 1032,46 1084,34 1137,23 1190,15 1244,8 1298,4 1353,1 1408,0 1464,2 1519,6 1575,12 1630,20 1687,31 1743,44 1799,59 1854,77 1911,98 1967,121 2022,147 2075,175 2131,206 2187,240 2240,276 2292,315 2345,359 2397,406 2499,502 2706,315 2730,294 2756,275 2782,256 2809,239 2865,206 2922,175 2951,161 2984,147 3054,122 3086,110 3113,98 3124,93 3133,87 3137,85 3140,82 3142,80 3144,77 3199,59 3254,44 3310,31 3367,20 3422,12 3478,6 3534,2 3590,0 3644,1 3699,4 3753,8 3807,15 3860,23 3913,34 3965,46 4017,61 4068,77 4118,94 4167,114 4215,135 4262,157 4309,181 4354,207 4399,234 4442,263 4484,293 4524,324 4564,357 4602,390 4638,425 4674,461 4708,498 4740,536 4770,575 4799,616 4826,657 4851,698 4875,741 4896,784 4916,829 4934,873 4950,918 4963,964 4974,1011 4983,1058 4990,1106 4995,1153 4997,1201 4997,1250 4994,1300 4989,1349 4981,1397 4976,1422 4970,1447 4955,1496 4923,1594 2499,5001 2498,5000 Z\"/>\n");
    printf("</symbol>\n");
}

/* turtle graphics */

double __turtleX = 148.5, __turtleY = 105, __turtleHeading = 0;

#define UP 0
#define CLEAN 1
#define DIRTY 2

#define TURTLE_STACK_SIZE 3072

static double __turtleStack[TURTLE_STACK_SIZE] = { 0 };
static int __turtleSP = 0;

void pushTurtle(void) {
    if (__turtleSP >= TURTLE_STACK_SIZE) {
        fprintf(stderr, "Turtle Stack Overflow!\n");
        return;
    }
    __turtleStack[__turtleSP++] = __turtleX;
    __turtleStack[__turtleSP++] = __turtleY;
    __turtleStack[__turtleSP++] = __turtleHeading;
}

void popTurtle(void) {
    if (__turtleSP <= 0) {
        fprintf(stderr, "Turtle Stack Underflow!\n");
        return;
    }
    __turtleHeading = __turtleStack[--__turtleSP];
    __turtleY       = __turtleStack[--__turtleSP];
    __turtleX       = __turtleStack[--__turtleSP];
}

int __turtlePen = CLEAN;  /* up: 0, down: 1, dirty: 2 */

void penUp(void) {
    if (__turtlePen == DIRTY) {
        /*    endShape(0);  */
    }
    __turtlePen = UP;
}

void finish(void) {
    penUp();
    resetMatrix();
    printf("</svg>\n");
}

void penDown(void) {
    if (__turtlePen == UP) {
        __turtlePen = CLEAN;
    }
}

void forward(double len) {
    double dx = len * cos360(__turtleHeading);
    double dy = len * sin360(__turtleHeading);
    if (__turtlePen == CLEAN) {
        __turtlePen = DIRTY;
        /*
                beginShape();
                vertex(__turtleX, __turtleY);
        */
    }
    if (__turtlePen == DIRTY) {
        line(__turtleX, __turtleY, __turtleX + dx, __turtleY + dy);
        /*        vertex(__turtleX + dx, __turtleY + dy); */
    }
    __turtleX += dx;
    __turtleY += dy;
}

void backward(double len) {
    double dx = - len * cos360(__turtleHeading);
    double dy = - len * sin360(__turtleHeading);
    __turtleX += dx;
    __turtleY += dy;
}

void turn(double angle) {
    int tmp;
    __turtleHeading += angle;

    tmp = (int)__turtleHeading;
    __turtleHeading -= tmp;
    if (__turtleHeading < 0) {
        __turtleHeading += 1;
        tmp--;
    }
    tmp %= 360;
    if (tmp < 0) {
        tmp += 360;
    }
    __turtleHeading += tmp;
}

void direction(double dir) {
    int tmp;
    __turtleHeading = dir;

    tmp = (int)__turtleHeading;
    __turtleHeading -= tmp;
    if (__turtleHeading < 0) {
        __turtleHeading += 1;
        tmp--;
    }
    tmp %= 360;
    if (tmp < 0) {
        tmp += 360;
    }
    __turtleHeading += tmp;
}

void go(double x, double y) {
    if (__turtleX != x || __turtleY != y) {
        if (__turtlePen == DIRTY) {
            penUp();
            __turtleX = x; __turtleY = y;
            penDown();
        } else {
            __turtleX = x; __turtleY = y;
        }
    }
}

void center(void) {
    go(148.5, 105);
}

double getX(void) {
    return __turtleX;
}

double getY(void) {
    return __turtleY;
}

double getAngle(void) {
    return __turtleHeading;
}

void say(const char *str, ...) {
    va_list list;
    va_start(list, str);
    pushMatrix();
    translate(__turtleX, __turtleY);
    rotate360(__turtleHeading);
    vtext(str, 0, 0, list);
    popMatrix();
    va_end(list);
}
