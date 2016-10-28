template <class T>
class sptr
{
public:
	sptr(T *ptr);
	sptr(sptr<T> &sptr);
	sptr<T> & operator=(sptr<T> & sptr);
	T operator *();
	T * operator ->();
	~sptr();
private:
	void remove();
	T *ref;
	unsigned *ref_count;
};