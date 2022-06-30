#include <Python.h>

typedef struct
{
    PyObject_VAR_HEAD
        uint32_t *item; /* the context holder */
} PyXHListObject;

extern PyTypeObject XHListType;

// typedef struct
// {
//     PyObject_HEAD 
//     long it_index;
//     PyXHListObject *it_seq; /* Set to NULL when iterator is exhausted */
// } XHListIterObject;

// extern PyTypeObject XHListIterType;