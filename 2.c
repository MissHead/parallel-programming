#include <stdio.h>

#include <stdlib.h>

#include <mpi.h>

#include <time.h>

void set_array(int * array, int tam, int num);
void sum(int * array, int tam);

int main() {

    int num_process;
    int id_process;
    char comunicator[MPI_MAX_PROCESSOR_NAME];
    int name_size;
    int * array;
    int value;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &num_process);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_process);
    MPI_Get_processor_name(comunicator, &name_size);


    if (id_process == 1) {
            fprintf(stderr, "\nEnter X:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 2);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter Y:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 2);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter W:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 2);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter Z:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 2);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }

    MPI_Bcast(&array[0], 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (id_process == 0) {
            fprintf(stderr, "\nEnter X:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 1);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter Y:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 1);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter W:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 1);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter Z:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 1);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }

    MPI_Bcast(&array[1], 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (id_process == 3) {
            fprintf(stderr, "\nEnter X:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 4);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter Y:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 4);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter W:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 4);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter Z:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 4);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }

    MPI_Bcast(&array[2], 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (id_process == 2) {
            fprintf(stderr, "\nEnter X:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 3);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter Y:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 3);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter W:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 3);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter Z:");
            scanf("%d", &value);
            array = (int*)calloc(value, sizeof(int));
            set_array(array, num_process, 3);
            MPI_Scatter(&array, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }

    MPI_Bcast(&array[3], 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (id_process == 0) {
        sum(array, num_process*4);
    }

    MPI_Finalize();

    return 0;
}

void set_array(int * array, int tam, int num) {
    int i;
    for (i = 0; i < tam; i++) {
        array[i] = i + num;
    }
}

void sum(int * array, int tam) {
    int i, sum;
    for(i=0; i<tam; i++) {
        sum = sum + array[i];
    }
    fprintf(stderr, "\nSum %d", sum);
}
