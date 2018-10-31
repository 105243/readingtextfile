#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QTextStream>
#include <QFile>

using namespace std;

struct Point{
    float x;
    float y;
};

float area();
float distance(Point A, Point B);
float perimeter();
void readtextfile();

QFile openfile("textpoints.txt");
QTextStream in(&openfile);
QString linepoints;
QStringList filepoints;
Point quadOne[5];

float area() {
    float AE = distance(quadOne[0],quadOne[4]);
    float AB = distance(quadOne[0],quadOne[1]);
    float BE = distance(quadOne[1],quadOne[4]);
    float BC = distance(quadOne[1],quadOne[2]);
    float CA = distance(quadOne[2],quadOne[0]);
    float CD = distance(quadOne[2],quadOne[3]);
    float DA = distance(quadOne[0],quadOne[3]);

    float p1 = (AB+BC+CA)/2;
    float p2 = (CD+DA+CA)/2;
    float p3 = (AE+BE+AB)/2;
    float area1 = sqrt(p1*(p1-AB)*(p1-BC)*(p1-CA));
    float area2 = sqrt(p2*(p2-CD)*(p2-DA)*(p2-CA));
    float area3 = sqrt(p3*(p3-BE)*(p3-AE)*(p3-AB));
    float area4 = area1+area2+area3;
    return area4;
}

float distance(Point A, Point B) {
    float distance = sqrt(pow(B.x-A.x,2)+pow(B.y-A.y,2));
    return distance;
}

float perimeter() {
    float AE = distance(quadOne[0],quadOne[4]);
    float BE = distance(quadOne[1],quadOne[4]);
    float BC = distance(quadOne[1],quadOne[2]);
    float CD = distance(quadOne[2],quadOne[3]);
    float DA = distance(quadOne[0],quadOne[3]);
    float perimeter = AE+BE+BC+CD+DA;
    return perimeter;
}

void readtextfile() {
    int i=0;

    while(!in.atEnd()) {
        linepoints = in.readLine();
        filepoints = linepoints.split(";");

        quadOne[i].x = filepoints.at(0).toFloat();
        quadOne[i].y = filepoints.at(1).toFloat();
        cout << " X: " << quadOne[i].x;
        if (quadOne[i].x > 0) cout << " ";
        cout << "  Y: " << quadOne[i].y << endl;
        i++;
    }
}


int main() {
    if (!openfile.exists()){
        cout << "Can't find file \"textpoints.txt\"";
        return -1;
    }
    if(!openfile.open(QIODevice::ReadOnly)) {
        cout << "Can't read file \"textpoints.txt\"";
        return -1;
    }
    readtextfile();
    cout << "\narea - " << area() << "\nperimeter - " << perimeter();
}

