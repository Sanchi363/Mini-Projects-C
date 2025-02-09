//A small task scheduler made using priortiy queue.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Task {
    char name[50];
    time_t submission_time;
    int priority; 
    struct Task* next; 
} Task;

Task* create_task(const char* name, int priority) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->submission_time = time(NULL);
    new_task->priority = priority;
    new_task->next = NULL;
    return new_task;
}

Task* add_task(Task* head, const char* name, int priority) {
    Task* new_task = create_task(name, priority);
    if (head == NULL || head->priority > priority) {
        new_task->next = head;
        head=new_task;
    } else {
        Task* current = head;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        new_task->next = current->next;
        current->next = new_task;
    }
    printf("Task '%s' added with priority %d.\n", name, priority);
    return head;
}

Task* complete_task(Task** scheduled_head, Task* completed_head) {
    if (*scheduled_head == NULL) {
        printf("No tasks to complete.\n");
        return completed_head; 
    }

    Task* completed_task = *scheduled_head;
    *scheduled_head = (*scheduled_head)->next;

    completed_task->next = completed_head;
    completed_head = completed_task;

    printf("Completed task: '%s' at %s", completed_task->name, ctime(&completed_task->submission_time));
    return completed_head;
}

void display_scheduled_tasks(Task* head) {
    if (head == NULL) {
        printf("No scheduled tasks.\n");
        return;
    }
    Task* current = head;
    printf("Scheduled Tasks:\n");
    while (current != NULL) {
        printf("Task: '%s', Priority: %d, Submitted at: %s", current->name, current->priority, ctime(&current->submission_time));
        current = current->next;
    }
}

void display_completed_tasks(Task* head) {
    if (head == NULL) {
        printf("No completed tasks.\n");
        return;
    }
    Task* current = head;
    printf("Completed Tasks:\n");
    while (current != NULL) {
        printf("Task: '%s', Completed at: %s", current->name, ctime(&current->submission_time));
        current = current->next;
    }
}

void free_tasks(Task* head) {
    while (head != NULL) {
        Task* next_task = head->next;
        free(head);
        head = next_task;
    }
}

int main() {
    Task* scheduled_tasks = NULL; 
    Task* completed_tasks = NULL; 
    int choice, priority;
    char name[50];

    while (1) {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. Complete Task\n");
        printf("3. Display Scheduled Tasks\n");
        printf("4. Display Completed Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf(" %[^\n]s", name); 
                printf("Enter task priority (lower number means higher priority): ");
                scanf("%d", &priority);
                scheduled_tasks = add_task(scheduled_tasks, name, priority); 
                break;
            case 2:
                completed_tasks = complete_task(&scheduled_tasks, completed_tasks); 
                scheduled_tasks = scheduled_tasks; 
                break;
            case 3:
                display_scheduled_tasks(scheduled_tasks);
                break;
            case 4:
                display_completed_tasks(completed_tasks);
                break;
            case 5:
                free_tasks(scheduled_tasks);
                free_tasks(completed_tasks);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
