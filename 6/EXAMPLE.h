#ifndef EXAMPLE
#define EXAMPLE

/*
class Example
{
public:
      example(double min, double max);
      example(const double* array, int size);
      double& operator[](int index);
      bool operator==(const example&) const;
      bool insert(const double*, int);
      bool insert(double);
      double min() const {  return m_dMin; }
      double max() const {  return m_dMax; }
      void min(double);
      void max(double);
      int count (double value) const;
private:
      int m_iSize;
      double* m_pdArray;
      double m_dMin;
      double m_dMax;
};
*/

template<typename T>
class Example
{
public:
	Example(T min, T max);
	Example(const T* array, int size);
	T& operator[](int index);
	bool operator==(const Example&) const;
	bool insert(const T*, int);
	bool insert(T);
	T min() const {return m_dMin;}
	T max() const {return m_dMax;}
	void min(T);
	void max(T);
	int count (T value) const;
	~Example();
private:
	int m_iSize;
	T* m_pdArray;
	T m_dMin;
	T m_dMax;

};

#endif