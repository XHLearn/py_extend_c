// https://docs.python.org/zh-cn/3/extending/extending.html

#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *SpamError;

static PyObject *spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;
    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    if(sts < 0){
        PyErr_SetString(SpamError, "System command failed!");
        return NULL;
    }
    return PyLong_FromLong(sts);
}

// 模块方法表和初始化函数
static PyMethodDef SpamMethods[] = {
    {"system", spam_system, METH_VARARGS, "Execute a shell command."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

PyMODINIT_FUNC initspam(void)
{
    PyObject *m;
    m = Py_InitModule3("spam", SpamMethods, "this is spam moudle");
    if(m == NULL)
        return;
    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_INCREF(SpamError);
    PyModule_AddObject(m, "error", SpamError);
}
