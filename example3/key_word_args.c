// https://docs.python.org/zh-cn/2.7/extending/extending.html

#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *SpamError;

static PyObject *keyword_arg_parrot(PyObject *self, PyObject *args, PyObject *keywords)
{
    int voltage;
    char *state = "a stiff";
    char *action = "voom";
    char *type = "Norwegian Blue";

    static char *kwlist[] = {"voltage", "state", "action", "type", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, keywords, "i|sss", kwlist,
                                     &voltage, &state, &action, &type))
        return NULL;

    printf("voltage:%i action:%s type:%s state:%s\n", voltage, action, type, state);

    Py_INCREF(Py_None);

    return Py_None;
}

// 模块方法表和初始化函数
static PyMethodDef KeywordArgsMethods[] = {
    {"parrot", (PyCFunction)keyword_arg_parrot, METH_VARARGS | METH_KEYWORDS, "Print a lovely skit to standard output."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

PyMODINIT_FUNC initkey_word_args(void)
{
    Py_InitModule3("key_word_args", KeywordArgsMethods, "this is keyword args moudle");
}
