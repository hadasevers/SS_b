/* 206398984 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "AdptArray.h"


// struct of ADT
typedef struct AdptArray_{
    PElement *arr_elm;  
    int len;
    DEL_FUNC del_fun;
    COPY_FUNC copy_fun;
    PRINT_FUNC prt_fun;
}AdptArray, *PAdptArray;


// create ADT
PAdptArray CreateAdptArray(COPY_FUNC copy, DEL_FUNC del,PRINT_FUNC prt)
{
    PAdptArray adt = (PAdptArray)malloc(sizeof(AdptArray));
    if (adt == NULL) return NULL;
    adt->arr_elm = NULL;
    adt->len = 0;
    adt ->copy_fun = copy;
    adt ->del_fun = del;
    adt ->prt_fun = prt;
    return adt;
}


void DeleteAdptArray(PAdptArray adt)
{
    // checking whether elements exist in th array
    if (adt->arr_elm == NULL) free(adt);
    else{
        for (int i = 0; i < GetAdptArraySize(adt); i++){
            if (adt->arr_elm[i] != NULL){
                adt->del_fun(adt->arr_elm[i]);
            }
        }
        free(adt->arr_elm);
        free(adt);
    }
}


Result SetAdptArrayAt(PAdptArray adt, int pos, PElement new_elm)
{
    int n_size = GetAdptArraySize(adt);

    // The array is shorter than pos
    if (n_size <= pos){     
        adt->arr_elm = realloc(adt->arr_elm, (pos+1)*sizeof(PElement)); 
        if (adt->arr_elm == NULL){
            return FAIL;
        }

        // "memset" the new cells
        for (int i = n_size; i < pos; i++){
            adt->arr_elm[i] = NULL;
        }
        adt->arr_elm [pos] = adt->copy_fun(new_elm);
        adt->len = pos+1; // update the len
    }

    // the cell number pos is exist
    else{
        if (adt->arr_elm[pos] != NULL){
            adt->del_fun(adt->arr_elm[pos]);
        }
        adt->arr_elm[pos] = adt->copy_fun(new_elm);
    }
    return SUCCESS;
}


PElement GetAdptArrayAt(PAdptArray adt, int pos)
{
    // Checking if exist element in the pos cell
    if ((adt->arr_elm == NULL) || (adt->arr_elm[pos] == NULL) || (GetAdptArraySize(adt) <= pos)){
        return NULL;
    }
    return adt->copy_fun(adt->arr_elm[pos]);
}


int GetAdptArraySize(PAdptArray adt)
{
    return adt->len;
}


void PrintDB(PAdptArray adt)
{
    // Checking if exist element in specific cell
    for (int i = 0; i < GetAdptArraySize(adt); i++){
        if (adt->arr_elm[i] != NULL){
            adt->prt_fun(adt->arr_elm[i]);
        }
    }
}
