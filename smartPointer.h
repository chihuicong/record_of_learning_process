#ifndef _SMARTPOINTER_H_
#define _SMARTPOINTER_H_

#include <iostream>
#include <assert.h>
#include <memory>

template <class T>
class SmartPointer{
public:
	SmartPointer(T *ptr = nullptr);
	~SmartPointer();
	SmartPointer(const SmartPointer& sp);
	SmartPointer& operator=(const SmartPointer& sp);
	T& operator*();
	T* operator->();
	size_t use_count();
private:
	T *ptr_;
	size_t *count_;
};

template <class T>
SmartPointer<T>::SmartPointer(T* ptr):ptr_(ptr){
	if(ptr_ == nullptr)
		count_ = new size_t(0);
	else
		count_ = new size_t(1);
}

template <class T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& sp){
	ptr_ = sp.ptr_;
	count_ = sp.count_;
	(*count_)++;
}

template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& sp){
	if(this == &sp)
		return *this;
	*(count_)--;
	if(*count_ == 0){
		delete ptr_;
		delete count_;
		ptr_ = nullptr;
		count_ = nullptr;
	}
	ptr_ = sp.ptr_;
	count_ = sp.count_;
	(*count_)++;
	return *this;
}

template <class T>
T& SmartPointer<T>::operator*(){
	assert(ptr_ != nullptr);
	return *ptr_;
}

template <class T>
T* SmartPointer<T>::operator->(){
	assert(ptr_ != nullptr);
	return ptr_;
}

template <class T>
SmartPointer<T>::~SmartPointer(){
	(*count_)--;
	if(*count_ == 0){
		delete ptr_;
		delete count_;
		ptr_ = nullptr;
		count_ = nullptr;
	}
}

template <class T>
size_t SmartPointer<T>::use_count(){
	assert(count_ != nullptr);
	return *count_;
}

#endif
