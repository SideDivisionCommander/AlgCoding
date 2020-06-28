void SelectSort(unsigned int* array, unsigned int len)
{
    for (unsigned int i = 0; i < len - 1; i++) {
        unsigned int minIndex = i; 
        for (unsigned int j = i + 1; j < len; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            unsigned int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

int leastInterval(char* tasks, int tasksSize, int n){
    //char status[26] = {0};
    unsigned int tasksNum[26] = {0};
    for (unsigned int i = 0; i < tasksSize; ++i) {
        tasksNum[tasks[i] - 'A']++;
    }
    unsigned int steps = 0;
    SelectSort(tasksNum, 26);
    while (tasksNum[25] > 0) {
        unsigned int i = 0;
        while (i <= n) {
            if (tasksNum[25] == 0) {
                break;
            }
            if (i < 26 && tasksNum[25-i] > 0) {
                tasksNum[25-i]--;
            }
            steps++;
            ++i;
        }
        SelectSort(tasksNum, 26);
    }
    return steps;
}
