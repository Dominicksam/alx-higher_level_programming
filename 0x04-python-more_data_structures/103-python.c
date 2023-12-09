#include <Python.h>

void print_python_list(PyObject *p) {
    if (!PyList_Check(p)) {
        fprintf(stderr, "Invalid Python list object\n");
        return;
    }

    Py_ssize_t size = PyList_Size(p);

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", size);

    printf("[*] Allocated = %zd\n", ((PyListObject *)p)->allocated);

    for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject *item = PyList_GetItem(p, i);
        const char *typeName = Py_TYPE(item)->tp_name;
        printf("Element %zd: %s\n", i, typeName);
    }
}

void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        fprintf(stderr, "Invalid Python bytes object\n");
        return;
    }

    Py_ssize_t size = PyBytes_Size(p);
    const char *bytes = PyBytes_AsString(p);

    printf("[.] bytes object info\n");
    printf("  [+] Size: %zd\n", size);
    printf("  [+] Address of the first byte: %p\n", (void *)bytes);
    printf("  [+] Bytes: ");
    
    for (Py_ssize_t i = 0; i < size && i < 10; ++i) {
        printf("%02hhx", bytes[i]);
        if (i < size - 1 && i < 9) {
            printf(" ");
        }
    }
    
    printf("\n");
}

int main(void) {
    Py_Initialize();

    PyObject *list = PyList_New(3);
    PyList_SetItem(list, 0, PyLong_FromLong(1));
    PyList_SetItem(list, 1, PyFloat_FromDouble(3.14));
    PyList_SetItem(list, 2, PyUnicode_DecodeUTF8("Hello", 5, "strict"));
    
    print_python_list(list);

    PyObject *bytes = PyBytes_FromStringAndSize("0123456789abcdef", 16);
    print_python_bytes(bytes);

    Py_Finalize();

    return 0;
}
