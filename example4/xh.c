#include "xhlist.h"

static PyObject *xhlist_new(PyObject *self, PyObject *args)
{
    PyObject *node;
    if (!PyArg_ParseTuple(args, "O", &node))
        return Py_None;
    long size = PyTuple_Size(node);
    PyXHListObject *result;
    result->ob_size = size;
    for (int i = 0; i < size; i++)
    {
        PyObject *n = PyTuple_GetItem(node, i);
        result->item[i] = PyInt_AsSsize_t(n);
    }
    return result;
}

static PyMethodDef xh_methods[] =
    {
        {"xhlist", xhlist_new, METH_VARARGS, "new xhlist"},
        {NULL, NULL, 0, NULL}};

PyMODINIT_FUNC init_xh(void)
{
    PyObject *m = Py_InitModule("xh", xh_methods);
    if (m == NULL)
        return;
    if (PyType_Ready(&XHListType) < 0)
        return;
}
