#include "xhlist.h"

static void xhlist_dealloc(PyXHListObject *obj)
{
    Py_ssize_t i;
    if (obj->item != NULL)
    {
        i = obj->ob_size;
        while (--i >= 0)
        {
            Py_XDECREF(obj->item[i]);
        }
        PyMem_FREE(obj->item);
    }
}

static void xhlist_print(PyXHListObject *obj, FILE *fp, int flags)
{
    Py_ssize_t i;
    fprintf(fp, "[");
    if (obj->item != NULL)
    {
        i = obj->ob_size;
        while (--i >= 0)
        {
            fprintf(fp, "%d", obj->item[i]);
        }
    }
    fprintf(fp, "]");
}

PyDoc_STRVAR(xhlist_doc, "xhlist()\nmy test xhlist");

static int xhlist_traverse(PyXHListObject *o, visitproc visit, void *arg)
{
    return 0;
}

// static PyObject *xhlist_iter(PyXHListObject *seq)
// {
//     XHListIterObject *it;
//     // it = PyObject_GC_New(XHListIterObject, &PyListIter_Type);
//     // if (it == NULL)
//     //     return NULL;
//     // it->it_index = 0;
//     // Py_INCREF(seq);
//     // it->it_seq = (PyXHListObject *)seq;
//     // _PyObject_GC_TRACK(it);
//     // return (PyObject *)it;
// }

static PyObject *xhlistcount(PyXHListObject *obj)
{
    return PyInt_FromSsize_t(obj->ob_size);
}

static PyMethodDef xhlist_methods[] = {
    {"count", (PyCFunction)xhlistcount, METH_NOARGS, "number of value"},
    {NULL, NULL} /* sentinel */
};

static PyObject *xhlist_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    return type->tp_alloc(type, 0);
}

PyTypeObject XHListType = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0) "xhlist", /*tp_name*/
    sizeof(PyXHListObject),                          /*tp_size*/
    0,                                               /*tp_itemsize*/
    /* methods */
    (destructor)xhlist_dealloc,                                    /*tp_dealloc*/
    (printfunc)xhlist_print,                                       /*tp_print*/
    0,                                                             /*tp_getattr*/
    0,                                                             /*tp_setattr*/
    0,                                                             /*tp_compare*/
    0,                                                             /*tp_repr*/
    0,                                                             /*tp_as_number*/
    0,                                                             /*tp_as_sequence*/
    0,                                                             /*tp_as_mapping*/
    0,                                                             /*tp_hash*/
    0,                                                             /*tp_call*/
    0,                                                             /*tp_str*/
    0,                                                             /*tp_getattro*/
    0,                                                             /*tp_setattro*/
    0,                                                             /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    xhlist_doc,                                                    /*tp_doc*/
    (traverseproc)xhlist_traverse, /*tp_traverse*/                 // 指向垃圾收集器的遍历函数的可选指针。这仅在设置了 Py_TPFLAGS_HAVE_GC 标志位时使用
    0,                                                             /*tp_clear*/
    0,                                                             /*tp_richcompare*/
    0,                                                             /*tp_weaklistoffset*/
    0,                                                             /*tp_iter*/
    0,                                                             /*tp_iternext*/
    xhlist_methods,                                                /*tp_methods*/
    0,                                                             /*tp_members*/
    0,                                                             /*tp_getset*/
    0,                                                             /* tp_base */
    0,                                                             /* tp_dict */
    0,                                                             /* tp_descr_get */
    0,                                                             /* tp_descr_set */
    0,                                                             /* tp_dictoffset */
    0,                                                             /* tp_init */
    0,                                                             /* tp_alloc */
    xhlist_new,                                                    /* tp_new */
    0,                                                             /* tp_free */
};
