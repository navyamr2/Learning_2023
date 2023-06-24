#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

float calculateDistance(struct Point p1, struct Point p2) {
    float distance;
    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return distance;
}

int main() {
    struct Point point1, point2;
    float distance;

    printf("Enter the coordinates of Point 1 (x y): ");
    scanf("%f %f", &point1.x, &point1.y);

    printf("Enter the coordinates of Point 2 (x y): ");
    scanf("%f %f", &point2.x, &point2.y);

    distance = calculateDistance(point1, point2);

    printf("The distance between the two points is: %.2f\n", distance);

    return 0;
}
