#include <stdio.h>

#include <stdlib.h>

#include <mpi.h>

#include <time.h>

void set_array(int*array, int tam);
void get_array(int*array, int tam);
void set_registry_array(char * array, int tam, char registry);
void calculate_media(int * vet1, int * vet2, int * vet3, int * vet4, char * students, int tam);

int main() {

    int num_process;
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
        fprintf("\nEnter number of student:"); 
        scanf("%d", &number_of_students);
        fflush(number_of_students);
        array = (int*)calloc(number_of_students, sizeof(int));
        set_array(array, number_of_students);
    }

    fprintf("\nBefore Gather: Comunicator: %s Id Process: %d\n", comunicator, num_process);

    MPI_Gather(number_of_students, 1, MPI_INT, array, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (id_process == 1) {
        begin = (number_of_students * 0) / 3;
        end = ((number_of_students * (0 + 1)) / 3) - 1;
        while (end != 0) {
            fprintf("Enter the 4 digits student registry number:");
            scanf("%s", registry[end]);
            fflush(registry[end]);
            fprintf("\nEnter first result of student:"); 
            scanf("%d", &final_result);
            fflush(final_result);
            result1 = (int*)calloc(final_result, sizeof(int));
            set_array(result1, final_result)
            fprintf("\nEnter second result of student:"); 
            scanf("%d", &final_result);
            fflush(final_result);
            result2 = (int*)calloc(final_result, sizeof(int));
            set_array(result2, final_result)
            fprintf("\nEnter fourth result of student:"); 
            scanf("%d", &final_result);
            fflush(final_result);
            result3 = (int*)calloc(final_result, sizeof(int));
            set_array(result3, final_result)
            fprintf("\nEnter fifth result of student:"); 
            scanf("%d", &final_result);
            fflush(final_result);
            result4 = (int*)calloc(final_result, sizeof(int));
            set_array(result4, final_result)
            end = end - 1;
        }
        array = (char*)calloc(number_of_students, sizeof(char));
        set_registry_array(array, end)
    }

    if (id_process == 2) {
        begin = (number_of_students * 1) / 3;
        end = ((number_of_students * (1 + 1)) / 3) - 1;
        while (end != 0) {
            fprintf("Enter the 4 digits student registry number:");
            scanf("%s", registry[end]);
            fflush(registry[end]);
            fprintf("\nEnter first result of student:"); 
            scanf("%d", &final_result);
            fflush(final_result);
            result1 = (int*)calloc(final_result, sizeof(int));
            set_array(result1, final_result)
            fprintf("\nEnter second result of student:"); 
            scanf("%d", &final_result);
            fflush(final_result);
            result2 = (int*)calloc(final_result, sizeof(int));
            set_array(result2, final_result)
            fprintf("\nEnter fourth result of student:"); 
            scanf("%d", &final_result);
            fflush(final_result);
            result3 = (int*)calloc(final_result, sizeof(int));
            set_array(result3, final_result)
            fprintf("\nEnter fifth result of student:"); 
            scanf("%d", &final_result);
            fflush(final_result);
            result4 = (int*)calloc(final_result, sizeof(int));
            set_array(result4, final_result)
            end = end - 1;
        }
        array = (char*)calloc(number_of_students, sizeof(char));
        set_registry_array(array, end);
    }

    if (id_process == 3) {
        begin = (number_of_students * 2) / 3;
        end = ((number_of_students * (2 + 1)) / 3) - 1;
        while (end != 0) {
            fprintf("Enter the 4 digits student registry number:");
            scanf("%s", registry[end]);
            fflush(registry[end]);
            fprintf("\nEnter first result of student:"); 
            scanf("%d", &final_result);
            fflush(final_result);
            result1 = (int*)calloc(final_result, sizeof(int));
            set_array(result1, final_result)
            fprintf("\nEnter second result of student:"); 
            scanf("%d", &final_result);
            fflush(final_result);
            result2 = (int*)calloc(final_result, sizeof(int));
            set_array(result2, final_result)
            fprintf("\nEnter fourth result of student:"); 
            scanf("%d", &final_result);
            fflush(final_result);
            result3 = (int*)calloc(final_result, sizeof(int));
            set_array(result3, final_result)
            fprintf("\nEnter fifth result of student:"); 
            scanf("%d", &final_result);
            fflush(final_result);
            result4 = (int*)calloc(final_result, sizeof(int));
            set_array(result4, final_result)
            end = end - 1;
        }
        array = (char*)calloc(number_of_students, sizeof(char));
        set_registry_array(array, end);
    }

    MPI_Gather(&registry[begin], 1, MPI_CHAR, array, 1, MPI_CHAR, 0, MPI_COMM_WORLD);

    MPI_Gather(final_result, 1, MPI_INT, result, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (id_process == 0) {
        fprintf("\nBefore Gather: Comunicator: %s Id Process: %d\n", comunicator, num_process);
        calculate_media(result1, result2, result3, result4, registry, number_of_students);
    }

    MPI_Finalize();

    return 0;
}

void set_array(int * array, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        array[i] = i + 1;
        fprintf("\nSet %d", array[i]);
        fflush(array[i]);
    }
}

void set_registry_array(char * array, int tam, char registry) {
    int i;
    for (i = 0; i < tam; i++) {
        array[i] = registry;
        fprintf("\nSet %s", array[i]);
        fflush(array[i]);
    }
}

void get_array(char * array, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        fprintf("\nGet %s", array[i]);
        fflush(array[i]);
    }
}

void calculate_media(int * vet1, int * vet2, int * vet3, int * vet4, char * students, int tam) {
    int i, media = 0;
    int medias[tam];
    char student;
    for(i=0; i<tam; i++)     {
        media = (vet1[i] + vet2[i] + vet3[i] + vet4[i])/4;
        medias[i] = media;
    }
    for (i=0; i<tam; i++) {
        if (medias[0] < medias[i]) {
            medias[0] = medias[i];
            student = students[i];
        }
    }

    fprintf("\nBest student: %s", student);
    fflush(student);
    fprintf("\nMedia: %d", medias[0]);
    fflush(medias[0]);
}