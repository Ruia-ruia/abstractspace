/* Status of setter function */
#include <string>
#include <vector>

using namespace std;

class Status {
public:
	Status(string d){ notes.push_back(d); }
	inline void note(string d) { notes.push_back(d); }
	inline void no(int num) { statno = num; }
	inline int get_no() { return statno; }
	vector<string>& get_notes() { return notes; }

private:
	vector<string> notes;
	int statno;
};
