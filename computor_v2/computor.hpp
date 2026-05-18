#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

struct polynome
{
	int deg;
	std::string name;
	std::vector<float> argg;
};

struct mat
{
	std::string name;
	std::vector<std::vector<float>> value;
};

struct vect
{
	std::string name;
	std::vector<float> value;
};

class data
{
private:
	std::vector<polynome> pol;
	std::vector<std::string> cst;
	std::vector<mat> matt;
	std::vector<vect> vct;

public:
	data(void) {};
	~data(void) {};
	void set_const(std::string name, float value);
	float get_cst(std::string nm);
	void set_function(std::vector<float>, std::string name);
	float get_img_function(std::string nm, float val);
	void set_matrice(std::vector<float>, std::string mane, int dim[2]);
	mat add_mat(mat m1, char op, mat m2);
	mat sub_mat(mat m1, mat m2);
	mat cst_mat(mat m, float f);
	vect add_vect(vect v1, vect v2);
	vect cst_vect(vect v, float f);
	void get_vect(std::string vect);
	void get_matrice(std::string matrice);
	size_t puiss(size_t nbr, int puis);
	int quit = 1;
	void update_data(std::string input);
};

std::string trim(const std::string& s);