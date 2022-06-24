/*
 * @Author: lamborghini1993
 * @Date: 2022-06-23 22:54:54
 */

#include<Python.h>

static PyObject* foo_bar(PyObject* self, PyObject* args){
    Py_RETURN_NONE;
}

static PyObject* add(PyObject* self, PyObject* args){
    int a, b;
    if(!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;
    return Py_BuildValue("i", a + b);
}

static PyMethodDef exampleMethods[] = {
    {"foo_bar", foo_bar, METH_NOARGS, NULL},
    {"add", add, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL}
};


PyMODINIT_FUNC initfoo(){
    Py_InitModule3("foo", exampleMethods, "foo module");
}