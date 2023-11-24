namespace bit
{
    template <class T>
    class vector
    {
    public:
        // Vector的迭代器是一个原生指针
        typedef T* iterator;
        typedef const T* const_iterator;

        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator cbegin() const
        {
            return _start;
        }

        const_iterator cend() const
        {
            return _finish;
        }
        // construct and destroy
        vector()
        :_start(nullptr)
        ,_finish(nullptr)
        ,_EndOfStorage(nullptr)
        {

        }

        vector(int n, const T &value = T())
            :_start(nullptr)
            ,_finish(nullptr)
            ,_EndOfStorage(nullptr)
        {
            reserve(n);
            for (size_t i = 0; i < n; i++)
            {
                push_back(value);
            }
        }

        template <class InputIterator>
        vector(InputIterator first, InputIterator last)
            : _start(nullptr)
            ,_finish(nullptr)
            ,_EndOfStorage(nullptr)
        {
            auto e = first;
            while(e!=last)
            {
                push_back(*e);
            }
        }

        vector(const vector<T>& v)
        {
            for(auto e:v)
            {
                push_back(*e);
            }
        }

        vector<T>& operator=(vector<T> v)
        {
            swap(v);
            return *this;
        }

        ~vector()
        {
            delete[] _start;
            _start = _finish = _EndOfStorage = nullptr;
        }
        // capacity
        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _EndOfStorage - _start;
        }

        void reserve(size_t n)
        {
            if(n>capacity())
            {
                T *tmp = new T[n];
                iterator it = begin();
                for (int i = 0; i < size(); i++)
                {
                    tmp[i] = _start[i];
                }
                _finish = tmp + size();
                _EndOfStorage = tmp + n;
                delete[] _start;
                _start = tmp;
            }
        }

        void resize(size_t n, const T &value = T())
        {
            if(n<=size())
            {
                _finish = _start + n;
            }
            else
            {
                reserve(n);
                while(_finish < _EndOfStorage)
                {
                    push_back(value);
                }
            }
        }

        ///////////////access///////////////////////////////
        T& operator[](size_t pos)
        {
            return _start[pos];
        }

        const T& operator[](size_t pos) const
        {
            return _start[pos];
        }
        ///////////////modify/////////////////////////////
        void push_back(const T &x)
        {
            // if (_finish == _EndOfStorage)
            //     reserve(capacity() == 0 ? 4 : 2 * capacity());
            // *_finish = x;
            // ++_finish;
            insert(end(), x);
        }

        void pop_back()
        {
            --_finish;
        }

        void swap(vector<T> &v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_EndOfStorage, v._EndOfStorage);
        }

        iterator insert(iterator pos, const T &x)
        {
            size_t i = pos - begin();
            if (_finish == _EndOfStorage)
                reserve(capacity() == 0 ? 4 : 2 * capacity());
            iterator it = end();
            while(it != begin() + i)
            {
                *it = *(it - 1);
                --it;
            }
            *(begin()+i) = x;
            ++_finish;
            return begin() + 1 + i;
        }

        iterator erase(iterator pos)
        {
            iterator i = pos;
            while(i != end())
            {
                *i = *(i + 1);
                ++i;
            }
            --_finish;
            return pos;
        }

    private:
        iterator _start; // 指向数据块的开始
        iterator _finish; // 指向有效数据的尾
        iterator _EndOfStorage; // 指向存储容量的尾
    };

}