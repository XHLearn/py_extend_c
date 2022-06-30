#include "xhlist.h"

static PyXHListObject *xhlist_new(PyObject *self, PyObject *args)
{
    if (!PyTuple_Check(args))
    {
        PyErr_SetString(PyExc_RuntimeError, "args invalid");
        return NULL;
    }

    PyXHListObject *result;
    uint32_t len = PyTuple_Size(args);

    fprintf(stderr, "%d", len);

    result->ob_size = len;
    for (int i = 0; i < len; i++)
    {
        PyObject *t = PyTuple_GetItem(args, i);
        PyObject_Print(t->ob_type, stderr, 0);
        if (!PyInt_Check(t))
        {
            PyErr_SetString(PyExc_TypeError, "args must be int");
            return NULL;
        }
        result->item[i] = PyLong_AsSsize_t(t);
    }
    return result;
}

static PyMethodDef xh_methods[] =
    {
        {"xhlist", xhlist_new, METH_VARARGS, "new xhlist"},
        {NULL, NULL, 0, NULL}};

PyMODINIT_FUNC initxh(void)
{
    PyObject *m = Py_InitModule("xh", xh_methods);
    if (m == NULL)
        return;
    if (PyType_Ready(&XHListType) < 0)
        return;
}
