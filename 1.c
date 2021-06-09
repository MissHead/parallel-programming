#include <stdio.h>

#include <stdlib.h>

#include <mpi.h>

#include <time.h>

void set_array(int*array, int tam);
void set_registry_array(char * array, int tam, char registry);
void calculate_media(int * vet1, int * vet2, int * vet3, int * vet4, char * students, int tam);

int main() {

    int num_process;
    int k = 0;
    int number_of_students;
    int id_process;
    char comunicator[MPI_MAX_PROCESSOR_NAME];
    int name_size;
    char * registry;
    int * result1;
    int * result2;
    int * result3;
    int * result4;
    int * array;
    int begin;
    int end;
    int final_result;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &num_process);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_process);
    MPI_Get_processor_name(comunicator, &name_size);


	if (id_process == 0) {
        fprintf(stderr, "\nEnter number of students:"); 
        scanf("%d", &number_of_students);
        array = (int*)calloc(number_of_students, sizeof(int));
        set_array(array, number_of_students);
    }

    MPI_Gather(&number_of_students, 1, MPI_INT, array, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (id_process == 1) {
        registry = (char*)calloc(number_of_students, sizeof(char));
        begin = (number_of_students * 0) / 3;
        end = ((number_of_students * (0 + 1)) / 3) - 1;
        for (k = 0; k < end; k++) {
            fprintf(stderr, "Enter the 4 digits student registry number:");
            scanf("%s", &registry[end]);
            set_registry_array(registry, number_of_students, registry[end]);
            MPI_Gather(&registry[end], 1, MPI_CHAR, registry, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter first result of student:"); 
            scanf("%d", &final_result);
            result1 = (int*)calloc(final_result, sizeof(int));
            set_array(result1, final_result);
            MPI_Gather(&final_result, 1, MPI_INT, result1, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter second result of student:"); 
            scanf("%d", &final_result);
            result2 = (int*)calloc(final_result, sizeof(int));
            set_array(result2, final_result);
            MPI_Gather(&final_result, 1, MPI_INT, result2, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter fourth result of student:"); 
            scanf("%d", &final_result);
            result3 = (int*)calloc(final_result, sizeof(int));
            set_array(result3, final_result);
            MPI_Gather(&final_result, 1, MPI_INT, result3, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter fifth result of student:"); 
            scanf("%d", &final_result);
            result4 = (int*)calloc(final_result, sizeof(int));
            set_array(result4, final_result);
            MPI_Gather(&final_result, 1, MPI_INT, result4, 1, MPI_INT, 0, MPI_COMM_WORLD);
        }
    }

    if (id_process == 2) {
        registry = (char*)calloc(number_of_students, sizeof(char));
        begin = (number_of_students * 1) / 3;
        end = ((number_of_students * (1 + 1)) / 3) - 1;
        for (k = 0; k < end; k++) {
            fprintf(stderr, "Enter the 4 digits student registry number:");
            scanf("%s", &registry[end]);
            set_registry_array(registry, number_of_students, registry[end]);
            MPI_Gather(&registry[end], 1, MPI_CHAR, registry, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter first result of student:"); 
            scanf("%d", &final_result);
            result1 = (int*)calloc(final_result, sizeof(int));
            set_array(result1, final_result);
            MPI_Gather(&final_result, 1, MPI_INT, result1, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter second result of student:"); 
            scanf("%d", &final_result);
            result2 = (int*)calloc(final_result, sizeof(int));
            set_array(result2, final_result);
            MPI_Gather(&final_result, 1, MPI_INT, result2, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter fourth result of student:"); 
            scanf("%d", &final_result);
            result3 = (int*)calloc(final_result, sizeof(int));
            set_array(result3, final_result);
            MPI_Gather(&final_result, 1, MPI_INT, result3, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter fifth result of student:"); 
            scanf("%d", &final_result);
            result4 = (int*)calloc(final_result, sizeof(int));
            set_array(result4, final_result);
            MPI_Gather(&final_result, 1, MPI_INT, result4, 1, MPI_INT, 0, MPI_COMM_WORLD);
        }
    }

    if (id_process == 3) {
        registry = (char*)calloc(number_of_students, sizeof(char));
        begin = (number_of_students * 2) / 3;
        end = ((number_of_students * (2 + 1)) / 3) - 1;
        for (k = 0; k < end; k++) {
            fprintf(stderr, "Enter the 4 digits student registry number:");
            scanf("%s", &registry[end]);
            set_registry_array(registry, number_of_students, registry[end]);
            MPI_Gather(&registry[end], 1, MPI_CHAR, registry, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter first result of student:"); 
            scanf("%d", &final_result);
            result1 = (int*)calloc(final_result, sizeof(int));
            set_array(result1, final_result);
            MPI_Gather(&final_result, 1, MPI_INT, result1, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter second result of student:"); 
            scanf("%d", &final_result);
            result2 = (int*)calloc(final_result, sizeof(int));
            set_array(result2, final_result);
            MPI_Gather(&final_result, 1, MPI_INT, result2, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter fourth result of student:"); 
            scanf("%d", &final_result);
            result3 = (int*)calloc(final_result, sizeof(int));
            set_array(result3, final_result);
            MPI_Gather(&final_result, 1, MPI_INT, result3, 1, MPI_INT, 0, MPI_COMM_WORLD);
            fprintf(stderr, "\nEnter fifth result of student:"); 
            scanf("%d", &final_result);
            result4 = (int*)calloc(final_result, sizeof(int));
            set_array(result4, final_result);
            MPI_Gather(&final_result, 1, MPI_INT, result4, 1, MPI_INT, 0, MPI_COMM_WORLD);
        }
    }

    if (id_process == 0) {
        calculate_media(result1, result2, result3, result4, registry, number_of_students);
    }

    MPI_Finalize();

    return 0;
}

void set_array(int * array, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        array[i] = i;
    }
}

void set_registry_array(char * registry, int tam, char registry_number) {
    int i;
    for (i = 0; i < tam; i++) {
        registry[i] = registry_number;
    }
}

void calculate_media(int * vet1, int * vet2, int * vet3, int * vet4, char * students, int tam) {
    int i, media = 0;
    int medias[tam];
    char * student;
    for(i=0; i<tam; i++)     {
        media = (vet1[i] + vet2[i] + vet3[i] + vet4[i])/4;
        medias[i] = media;
    }
    for (i=0; i<tam; i++) {
        if (medias[0] < medias[i]) {
            medias[0] = medias[i];
            student = &students[i];
        }
    }

    fprintf(stderr, "\nBest student: %s", student);
    fprintf(stderr, "\nMedia: %d", medias[0]);
}
