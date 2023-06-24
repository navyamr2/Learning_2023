#include <stdio.h>

struct Box {
    float length;
    float width;
    float height;
};

float calculateVolume(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

float calculateSurfaceArea(struct Box* boxPtr) {
    return 2 * (boxPtr->length * boxPtr->width +
                boxPtr->length * boxPtr->height +
                boxPtr->width * boxPtr->height);
}

int main() {
    struct Box box;

    // Prompt the user to enter the dimensions of the box
    printf("Enter the length of the box: ");
    scanf("%f", &(box.length));
    printf("Enter the width of the box: ");
    scanf("%f", &(box.width));
    printf("Enter the height of the box: ");
    scanf("%f", &(box.height));

    struct Box* boxPtr = &box;

    // Access members with (*) asterisk or indirection operator and (.) dot operator
    float volume = (*boxPtr).length * (*boxPtr).width * (*boxPtr).height;
    float surfaceArea = 2 * ((*boxPtr).length * (*boxPtr).width +
                             (*boxPtr).length * (*boxPtr).height +
                             (*boxPtr).width * (*boxPtr).height);

    printf("Volume of the box: %.2f\n", volume);
    printf("Surface Area of the box: %.2f\n", surfaceArea);

    // Access members with (->) arrow operator using pointer as well as dot representation
    float volume2 = boxPtr->length * boxPtr->width * boxPtr->height;
    float surfaceArea2 = 2 * (boxPtr->length * boxPtr->width +
                              boxPtr->length * boxPtr->height +
                              boxPtr->width * boxPtr->height);

    printf("Volume of the box (using arrow operator): %.2f\n", volume2);
    printf("Surface Area of the box (using arrow operator): %.2f\n", surfaceArea2);

    return 0;
}
