/*
 * List.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <stdexcept>

template<typename T>
class List {
	struct node {
		node(node* pred, node* succ, const T& item) :
				pred(pred), succ(succ), item(item) {
		}

		node* pred;
		node* succ;
		T item;
	};

	node* _sentinel;
	int count;

	template<typename U>
	class iterator_base {
	public:
		iterator_base(node* ptr) :
				ptr(ptr) {
		}

		iterator_base& operator=(const iterator_base& other) {
			if (!(*this == other))
				this->ptr = other.ptr;
			return *this;
		}

		iterator_base& operator++() {
			this->ptr = this->ptr->succ;
			return *this;
		}

		iterator_base& operator++(int) {
			iterator_base other(this);
			++this;
			return other;
		}

		/*iterator_base& operator+(int n) {
			iterator_base<U>* it = new iterator_base<U>(this->ptr);
			if (n < 0) {
				return this->operator -(-n);
			}
			while (--n > 0) {
				++it;
				if (sentinel == it->ptr)
					++n;
			}
			return *it;
		}*/

		iterator_base& operator--() {
			this->ptr = this->ptr->pred;
			return *this;
		}

		iterator_base& operator--(int) {
			iterator_base other(this);
			--this;
			return other;
		}

		/*iterator_base& operator-(int n) {
			iterator_base<U>* it = new iterator_base<U>(this->ptr);
			if (n < 0) {
				return this->operator +(-n);
			}
			while (--n > 0) {
				--it;
				if (sentinel == it->ptr)
					--n;
			}
			return *it;
		}*/

		bool operator==(const iterator_base& other) const {
			return this->ptr == other.ptr;
		}

		bool operator!=(const iterator_base& other) const {
			return !(*this == other);
		}

		U& operator*() const {
			return this->ptr->item;
		}

		U* operator->() const {
			return &(this->ptr->item);
		}

	private:
		node* ptr;
	};

public:
	List() :
			_sentinel(new node(0, 0, T())), count(0) {
		_sentinel->succ = _sentinel->pred = _sentinel;
	}

	virtual ~List() {
		while (_sentinel->succ != _sentinel) {
			this->_sentinel->succ = this->_sentinel->succ->succ;
			delete this->_sentinel->succ->pred;
		}
	}

	bool empty() const {
		return this->count == 0;
	}

	int size() const {
		return this->count;
	}

	T back() const {
		return _sentinel->pred->item;
	}

	T front() const {
		return _sentinel->succ->item;
	}

	/**
	 * Operações de inserção
	 */
	void push(int position, const T& item) {
		if (position == 0) {
			push_front(item);
			return;
		} else if (position == count) {
			push_back(item);
			return;
		} else if (position < 0 || position > count) {
			throw std::out_of_range("Inserting out of bounds");
		}

		node* aux = _sentinel->succ;
		for (int i = 0; i < position; ++i) {
			aux = aux->succ;
		}

		/*
		 * Mudar o predecessor do sucessor de aux ->
		 *** Sucessor do predecessor de aux aponta para novo item
		 *** Predecessor de aux aponta para novo item
		 * Tempo: O(1)
		 */
		aux->pred = aux->pred->succ = new node(aux->pred, aux, item);
		++count;
	}

	void push_back(const T& item) {
		/*
		 * Mudar o predecessor do sucessor da sentinela ->
		 *** Sucessor do predecessor da sentinela aponta para novo item
		 *** Predecessor da sentinela aponta para novo item
		 */
		_sentinel->pred = _sentinel->pred->succ = new node(_sentinel->pred,
				_sentinel, item);
		++this->count;
	}

	void push_front(const T& item) {
		/*
		 * Mudar o sucessor do predecessor da sentinela ->
		 *** Predecessor do sucessor da sentinela aponta para novo item
		 *** Sucessor da sentinela aponta para novo item
		 */
		_sentinel->succ = _sentinel->succ->pred = new node(_sentinel,
				_sentinel->succ, item);
		++this->count;
	}

	/**
	 * Operações de remoção
	 */
	T pop_back() {
		if (this->count) {
			T removed = this->_sentinel->pred->item;
			this->_sentinel->pred = this->_sentinel->pred->pred;
			delete this->_sentinel->pred->succ;
			this->_sentinel->pred->succ = this->_sentinel;
			--this->count;
			return removed;
		} else {
			throw std::out_of_range("Empty list.");
		}
	}

	T pop(int position) {
		if (position == 0) {
			return this->pop_front();
		} else if (position == this->count - 1) {
			return this->pop_back();
		} else if (position < 0 && position >= this->count) {
			throw std::out_of_range("Invalid position.");
		}
		node* exNode = this->_sentinel->succ; // será o nó que estava na posição escolhida
		for (int i = 0; i < position; ++i) {
			exNode = exNode->succ;
		}
		T removed = exNode->item;
		exNode->pred->succ = exNode->succ;
		exNode->succ->pred = exNode->pred;
		delete exNode;
		--this->count;
		return removed;
	}

	T pop_front() {
		if (this->empty()) {
			throw std::out_of_range("Empty list.");
		} else {
			T removed = this->_sentinel->item;
			this->_sentinel->succ = this->_sentinel->succ->succ;
			delete this->_sentinel->succ->pred;
			this->_sentinel->succ->pred = this->_sentinel;
			--this->count;
			return removed;
		}
	}

	typedef iterator_base<T> iterator;
	typedef iterator_base<const T> const_iterator;

	iterator begin() {
		return iterator(this->_sentinel->succ);
	}

	iterator end() {
		return iterator(this->_sentinel);
	}

	iterator rbegin() {
		return iterator(this->_sentinel->pred);
	}

	iterator rend() {
		return iterator(this->_sentinel);
	}

	const_iterator begin() const {
		return const_iterator(this->_sentinel->succ);
	}

	const_iterator end() const {
		return const_iterator(this->_sentinel);
	}

	const_iterator rbegin() const {
		return const_iterator(this->_sentinel->pred);
	}

	const_iterator rend() const {
		return const_iterator(this->_sentinel);
	}
};

#endif /* LIST_H_ */
