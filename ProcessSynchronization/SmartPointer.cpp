#include "SmartPointer.h"

template <class T> sptr <T>::sptr(T *ptr)
{
	ref = ptr;
	ref_count = (unsigned *)malloc(sizeof(unsigned));
	*ref_count = 1;
}

template <class T> sptr <T>::sptr(sptr<T> &sptr)
{
	ref = sptr.ref;
	ref_count = sptr.ref_count;
	(*ref_count)++;
}

template <class T> sptr <T> & sptr <T>::operator=(sptr<T> &sptr)
{
	if (*ref_count > 0)
	{
		remove();
	}

	if (this != &sptr)
	{
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		(*ref_count)++;
	}

	return *this;
}

template <class T> T sptr <T>::operator*()
{
	return *ref;
}

template <class T> T * sptr <T>::operator->()
{
	return ref;
}

template <class T> void sptr <T>::remove()
{
	(*ref_count)--;
	if (ref_count == 0)
	{
		delete ref;
		free(ref_count);
		ref = NULL;
		ref_count = NULL;
	}
}

template <class T> sptr <T>::~sptr()
{
	remove();
}