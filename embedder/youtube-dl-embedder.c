#include <Python.h>

char *
ydle_resolve_url(const char *url)
{
  PyObject *pModule, *pDict, *pFunc;
  PyObject *pArgs, *pValue;
  char *result = NULL;
  int i;

  Py_Initialize();

  pModule = PyImport_Import(PyString_FromString("youtube_dl_url_resolver"));

  if (pModule != NULL) {
    pFunc = PyObject_GetAttrString(pModule, "get_urls");
    /* pFunc is a new reference */

    if (pFunc && PyCallable_Check(pFunc)) {
      pArgs = PyTuple_New(1);
      pValue = PyString_FromString(url);
      if (!pValue) {
        Py_DECREF(pArgs);
        Py_DECREF(pModule);
        fprintf(stderr, "Cannot convert argument\n");
        goto done;
      }
      /* pValue reference stolen here: */
      PyTuple_SetItem(pArgs, 0, pValue);
      pValue = PyObject_CallObject(pFunc, pArgs);
      Py_DECREF(pArgs);
      if (pValue != NULL) {
        result = PyString_AsString(pValue);
        Py_DECREF(pValue);
      }
      else {
        Py_DECREF(pFunc);
        Py_DECREF(pModule);
        PyErr_Print();
        fprintf(stderr,"Call failed\n");
        goto done;
      }
    }
    else {
      if (PyErr_Occurred())
        PyErr_Print();
      fprintf(stderr, "Cannot find function \"%s\"\n", "get_urls");
    }
    Py_XDECREF(pFunc);
    Py_DECREF(pModule);
  }
  else {
    PyErr_Print();
    fprintf(stderr, "Failed to load \"%s\"\n", "youtube_dl_url_resolver");
    goto done;
  }
  Py_Finalize();

done:
  return result;
}
