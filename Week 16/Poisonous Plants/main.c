#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
  int value;
  int day;
} Node;

int main(void) {
  int length = 0;
  scanf("%d\n", &length);

  int *array = (int*)calloc(length, sizeof(int));
  for (int i = 0; i < length; i++) {
    scanf("%d", &array[i]);
  }
  Node *stack = (Node*)calloc(length, sizeof(Node));
  int top_index = -1;

  int min_value_so_far = array[0];
  int max_alive_days = 0;
  for (int i = 1; i < length; i++) {
    // Pop elements off the stack with greater or equal value and track the maximum day seen
    int days_alive = 0;
    while (top_index > -1 && stack[top_index].value >= array[i]) {
      if (days_alive < stack[top_index].day) days_alive = stack[top_index].day;
      top_index--;
    }
    // If this value is a left-to-right minimum, it will never die
    if (array[i] <= min_value_so_far) {
      min_value_so_far = array[i];
    } else {
      top_index++;
      stack[top_index].value = array[i];
      stack[top_index].day = days_alive + 1;
      if (max_alive_days < days_alive + 1) max_alive_days = days_alive + 1;
    }
  }

  // Check for the maximum of anything remaining in the stack
  while (top_index > -1) {
    if (max_alive_days < stack[top_index].day) max_alive_days = stack[top_index].day;
    top_index--;
  }

  printf("%d\n", max_alive_days);

  free(array);
  free(stack);
  return 0;
}
