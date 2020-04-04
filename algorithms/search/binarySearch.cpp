/**
    O(log n) Divide and Conquer search algorithm for sorted arrays.
    Used for:
    Finding local maximum or minimum of a function. ("Where the function changes")
*/

int binarySearch(int needle, int haystack[], int hayStackSize) {
    int startIndex = 0;
    int endIndex = hayStackSize - 1;

    while (startIndex <= endIndex) {
        int currentIndex = (startIndex + endIndex) / 2;
        if (haystack[currentIndex] == needle) {
            return currentIndex;
        } else if (haystack[currentIndex] > needle) {
            endIndex = currentIndex - 1;
        } else {
            startIndex = currentIndex + 1;
        }
    }
}
