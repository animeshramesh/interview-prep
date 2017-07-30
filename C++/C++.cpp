// Classes
class Person
{
	int id; // All members are private by default
	string name;

public:
	void printName()
	{
		cout << "Animesh\n";
	}
	Person(string name, int id)
	{
		this->name = name;
		this->id = id;
	}
};

// Objects
Person p("Animesh", 1);	// Will be automatically deleted
Person * p = new Person(); // Need to manually delete this using delete p

// Struct
struct product {
  int weight;
  double price;
} apple; // can instantiate new structure variable here

// Structs can have constructors!!
product apple; // or like this. Use dot operator to access member variables
// Member of a class defined with the keyword class are private by default. 
// Members of a class defined with the keywords struct or union are public by default.


// Inheritance


// Virtual Functions



// Vector
vector<int> first;
vector<int> v = {1, 2, 3, 4};	// Initialization 
vector<int> second (4,100);	// 4 ints with value = 100
vector<int> fourth (third); // copy of 3rd
vec.size() // size of vector
vec.resize(5) // resizes the vector so it contains n elements
vec.empty() // vec.size() == 0
vec.push_back(5)
vec.pop_back() // removes last element
it = vec.insert(vec.begin(), 1) // returns iterator which points to 1


// String - almost same as vector
str += "animesh";
str.find_first_of('0') // searches for the first occurence of character. Returns -1 if not found
str.find_first_not_of('0')	// used for multiply string
str.find_last_of('0') // searches from the end
str.find_last_not_of('0')
str.substr(i, len)
str.pop_back()
str.push_back()

// Stacks
empty(), size()
top()
push(n), pop()


// Queues
empty(), size()
front(), back()
push(), pop()


// Set, unordered_set
// Sets are containers that store unique elements following a specific order.
set.insert(10), set.insert(set.begin(), 10)
set.find()
// Unordered sets are containers that store unique elements in no particular order, 
// and which allow for fast retrieval of individual elements based on their value


// Map, unordered_map
map.find(x)
map.rbegin(), map.rend() -> reverse iterator

// Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.
// Unordered maps - keys are in no specific order


// Use pairs when possible
pair<int, int> p
p.first, p.second


// List
// Lists are doubly linked lists!! Used for LRU cache
list<int> l;
l.push_front(1), l.push_back(1);
l.pop_front(), l.pop_front();
l.front(), l.back()	// element access

// Use typedef to shrink code in interviews
typedef unordered_map<char, unordered_set<char>> graph;

// Priority queues
// Bu default, the largest element is the first element (max-heap)

// C++ 11 stuff


// Exceptions
double division(int a, int b) 
{
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}
try
{
	z = division(x, y);
}
catch (string msg) 
{
	cout << msg;
}



