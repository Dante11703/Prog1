
            //------------elso resz------------//


/*#include<iostream>
#include<vector>
#include<exception>
#include<fstream>
#include<algorithm>
#include<list>

using namespace std;

struct Item
{
	Item(string n, int i, double v): name(n), iid(i), value(v) {}
	string name;
	int iid;
	double value;

	//bool operator==(const Item& i1) { return name == i1.name; }
};

ostream& operator<<(ostream& os, const Item& i)
{
	os << i.name << ' ' << i.iid << ' ' << i.value;
	return os;
}

template<typename Iter>
void printout(const Iter& first, const Iter& last)
{
	for (auto p = first; p != last; ++p)
		cout << *p << ' ' << endl;
}

class compByName
{
private:
	string name;
public:
	compByName(const string& s): name{s} {}
	bool operator()(const Item& i) const { return i.name == name; }
};

class compById
{
private:
	int id;
public:
	compById(const int& idd): id(idd) {}
	bool operator()(const Item& i) const { return i.iid == id; }
};

void format() { cout << "-----------------------------------------------------" << endl; }

int main()
try {
	vector<Item> vi;
	string n;
	int id;
	double val;

	// file handling
	string filename = "p1_infile.txt";
	ifstream is {filename};
	if (!is) cout << "Can't open file!" << endl;

	// reading in datas
	while (is >> n >> id >> val) { vi.push_back(Item{n, id, val}); }

	// sortings
	// sorting by name
	sort(vi.begin(), vi.end(), 
		[] (const Item& i1, const Item& i2) { return i1.name < i2.name; });
	// sorting by id
	sort(vi.begin(), vi.end(), 
		[] (const Item& i1, const Item& i2) { return i1.iid < i2.iid; });
	// sorting by value, descendent
	sort(vi.begin(), vi.end(), 
		[] (const Item& i1, const Item& i2) { return i1.value > i2.value; });

	format();

	// printing out the elements after sorting
	cout << "### Vector elements after sorting ###" << endl;
	printout(vi.begin(), vi.end());

	// insertions
	vi.insert(vi.end(), Item{"horse shoe", 99, 12.34});
	vi.insert(vi.end(), Item{"Canon S400", 9988, 499.95});

	format();

	// printing out the elements after inserting
	cout << "### Vector elements after inserting ###" << endl; 
	printout(vi.begin(), vi.end());

	// erase by name
	auto name_erase = find_if(vi.begin(), vi.end(), compByName("ajto"));
	vi.erase(name_erase);
	// erase by id
	auto id_erase = find_if(vi.begin(), vi.end(), compById(1));
	vi.erase(id_erase);

	format();

	//printing out after erase
	cout << "### Vector elements after erasing ###" << endl; 
	printout(vi.begin(), vi.end());

	return 0;
} catch (exception& e) {
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "Something went wrong!" << endl;
	return 2;
}

*/


//-------------- masodik resz ------------//



/*#include<iostream>
#include<vector>
#include<exception>
#include<fstream>
#include<algorithm>
#include<list>

using namespace std;

struct Item
{
	Item(string n, int i, double v): name(n), iid(i), value(v) {}
	string name;
	int iid;
	double value;
};

ostream& operator<<(ostream& os, const Item& i)
{
	os << i.name << ' ' << i.iid << ' ' << i.value;
	return os;
}

template<typename Iter>
void printout(const Iter& first, const Iter& last)
{
	for (auto p = first; p != last; ++p)
		cout << *p << ' ' << endl;
}

class compByName
{
private:
	string name;
public:
	compByName(const string& s): name{s} {}
	bool operator()(const Item& i) const { return i.name == name; }
};

class compById
{
private:
	int id;
public:
	compById(const int& idd): id(idd) {}
	bool operator()(const Item& i) const { return i.iid == id; }
};

bool sortByName(const Item& item1, const Item& item2)
{
	return item1.name < item2.name;
}

bool sortById(const Item& item1, const Item& item2)
{
	return item1.iid < item2.iid;
}

bool sortByValDesc(const Item& item1, const Item& item2)
{
	return item1.value > item2.value;
}

void format() { cout << "-----------------------------------------------------" << endl; }

int main()
try {
	list<Item> ls;
	string n;
	int id;
	double val;

	// file handling
	string filename = "p1_infile.txt";
	ifstream is {filename};
	if (!is) cout << "Can't open file!" << endl;

	// reading in datas
	while (is >> n >> id >> val) { ls.push_back(Item{n, id, val}); }

	
	// sortings
	ls.sort(sortByName); // sorting by name
	ls.sort(sortById); // sorting by id
	ls.sort(sortByValDesc); // sorting by value, descendent

	format();

	// printing out the elements after sorting
	cout << "### List elements after sorting ###" << endl;
	printout(ls.begin(), ls.end());

	// insertions
	ls.insert(ls.end(), Item{"horse shoe", 99, 12.34});
	ls.insert(ls.end(), Item{"Canon S400", 9988, 499.95});

	format();

	// printing out the elements after inserting
	cout << "### List elements after inserting ###" << endl; 
	printout(ls.begin(), ls.end());

	// erase by name
	auto name_erase = find_if(ls.begin(), ls.end(), compByName("ajto"));
	ls.erase(name_erase);
	// erase by id
	auto id_erase = find_if(ls.begin(), ls.end(), compById(1));
	ls.erase(id_erase);

	format();

	//printing out after erase
	cout << "### List elements after erasing ###" << endl; 
	printout(ls.begin(), ls.end());

	return 0;
} catch (exception& e) {
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "Something went wrong!" << endl;
	return 2;
}*/



//--------------------- harmadik resz --------------//



/*
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<exception>

using namespace std;

void read_val(map<string, int>& m)
{
	string s;
	int val;
	cin >> s >> val;
	m.insert({s, val});
}

template<typename T1, typename T2>
void print_map(const map<T1, T2> mapp, const string& str)
{
	cout << str << endl;
	for (const auto& e : mapp) cout << e.first << ' ' << e.second << endl;
}

void format() { cout << "-----------------------------------------------------" << endl; }

double map_int_sum(const map<string, int>& mapp)
{
	int sum = 0;
	for (const auto& e : mapp) sum += e.second;
	return sum;
}

int main()
try {
	map<string, int> msi;

	// inserting 10 elements into the map
	msi.insert({"prog", 21});
	msi.insert({"lecture", 11});
	msi.insert({"info", 31});
	msi.insert({"magyar", 12});
	msi.insert({"diszkmat", 22});
	msi.insert({"oprendszer", 23});
	msi.insert({"kalkulus", 24});
	msi.insert({"terinfo", 25});
	msi.insert({"halozati", 22});
	msi.insert({"adatbazis", 20});

	print_map(msi, "MSI elements: ");

	format();

	// erasing
	msi.erase(msi.begin(), msi.end());

	// reading value pairs
	cout << "Please enter 10 pairs of 'string' and 'int': " << endl;
	constexpr int how_many = 10;
	for (int i = 0; i < how_many; ++i) read_val(msi);
	format();
	// printing out these elements
	print_map(msi, "New read values of msi: ");

	format();

	// sum of map's elements
	cout << "Sum of map's 'int' elements: " << map_int_sum(msi) << endl;

	format();

	// reversed pairs of 'msi'
	map<int, string> mis;
	for (const auto& m : msi) mis.insert({m.second, m.first});
	print_map(mis, "Data pairs of 'mis': ");

	return 0;
} catch (exception& e) {
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "Something went wrong!" << endl;
	return 2;
}*/


//----------------- utolso resz --------------//


#include<iostream>
#include<vector>
#include<exception>
#include<fstream>
#include<algorithm>

using namespace std;

template<typename Iter>
void printout(const Iter& first, const Iter& last, const string& s)
{
	cout << s << endl;
	for (auto p = first; p != last; ++p)
		cout << *p << ' ';
	cout << endl;
}

template<typename InputIt, typename T, class BinaryOperation>
T my_accumulate(InputIt first, InputIt last, T init, BinaryOperation op)
{
	while(first != last) 
	{
		init = op(init, *first);
		++first;
	}
	return init;
}

template<typename InputIt>
double my_mean(InputIt first, InputIt last)
{
	double sum = my_accumulate(first, last, 0.0, plus<double>());
	int elem_nb = distance(first, last);
	return sum/elem_nb;
}

void format() { cout << "-----------------------------------------------------" << endl; }

int main()
try {
	vector<double> vd;

	// file handling
	string filename = "p3_infile.txt";
	ifstream is {filename};
	if (!is) cout << "Can't open file!" << endl;

	// reading in datas
	double data;
	while (is >> data) { vd.push_back(data); }

	// printing out the default datas
	printout(vd.begin(), vd.end(), "VD datas: ");

	format();

	// copying 'vd' into 'vi'
	vector<int> vi(vd.size());
	copy(vd.begin(), vd.end(), vi.begin());

	// writing out 'vi'
	printout(vi.begin(), vi.end(), "VI copied datas: ");

	format();

	// printing out the pairs
	cout << "Element pairs: " << endl;
	for (int i = 0; i < vi.size(); ++i) cout << vd[i] << ' ' << vi[i] << endl; 

	format();

	// summing and outputting
	double vd_sum = my_accumulate(vd.begin(), vd.end(), 0.0, plus<double>());
	cout << "Sum of vd's elements: " << vd_sum << endl;

	format();

	// diff between sum of vd's elements and of vi's elements
	int vi_sum = my_accumulate(vi.begin(), vi.end(), 0, plus<int>());
	cout << "Diff between vd's elem. and of vi's elem.: " << vd_sum-vi_sum << endl;

	format();

	// reversing
	reverse(vd.begin(), vd.end());
	printout(vd.begin(), vd.end(), "Reversed 'vd': ");

	format();

	// mean/avg of 'vd'
	double avg = my_mean(vd.begin(), vd.end());
	cout << "VD mean: " << avg << endl;

	format();

	// copying elements which are less than vd's mean
	vector<double> vd2;
	copy_if(vd.begin(), vd.end(), back_inserter(vd2), [avg] (const double& val) { return val < avg; });
	printout(vd2.begin(), vd2.end(), "Elements of vd which are less than its average: ");


	return 0;
} catch (exception& e) {
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "Something went wrong!" << endl;
	return 2;
}