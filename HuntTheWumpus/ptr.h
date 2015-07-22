#ifndef _LAZY_PTR_H__
#define _LAZY_PTR_H__
namespace lazy
{
	template<class T>
	class Ptr
	{
	public:
		Ptr():reference(0){}
		Ptr(T* _reference):reference(_reference){}
		T* operator->() { return _reference;}
		T& operator*() { return *_reference;}
		~Ptr() { delete reference;}
		T* Release() { return _reference;}

	private:
		Ptr(const Ptr&);
		Ptr& operator=(const Ptr&);

		T* reference;
	};

	template<class T>
	class CountedPtr
	{
	public:
		CountedPtr():ref_count(0), reference(0){}

		CountedPtr(T* _reference)
			:ref_count(new int(1)), reference(_reference)
		{
			AddRef();
		}

		CountedPtr(const CountedPtr<T>& _ptr)
		{
			reference = _ptr.reference;
			ref_count = _ptr.ref_count;
			AddRef();
		}

		CountedPtr<T>& operator=(const CountedPtr<T>& _ptr)
		{
			if(this != &_ptr)				
			{
				Release();
				reference = _ptr.reference;
				ref_count = _ptr.ref_count;
				AddRef();		
			}
			return *this;
		}

		CountedPtr<T>& operator=(T* _ptr)
		{
			Release();
			if(_ptr)
			{
				reference = _ptr;
				ref_count = new int(1);
			}
			else
			{
				reference = 0;
				ref_count = 0;
			}
			return *this;
		}

		~CountedPtr<T>()
		{ 
			Release();			
		}

		const T* operator->() const
		{
			return reference;
		}

		const T& operator*() const
		{ 
			return *reference;
		}

		T* operator->()
		{
			return reference;
		}

		T& operator*()
		{
			return *reference;
		}

	private:
		void AddRef() { if(ref_count) ++*ref_count; }
		void Release() 
		{ 
			if(ref_count)
			{
				if(--*ref_count == 0) 
				{
					delete reference;
					delete ref_count;
					reference = 0;
					ref_count = 0;
				}
			}				
		}
		int* ref_count;
		T* reference;
	};
}

#endif // !_LAZY_PTR_H__
