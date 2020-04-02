// 
//
//  Lab 10
//
//  Created by Mohammed Shehab on 4/1/2020.
//  Copyright © 2020 Mohammed Shehab. All rights reserved.
//
#pragma once
#include <vector>


class Average {
private:
	double ave_stream;
	double ave_real;
	int count;
	std::vector<int> all_data;

public:
	Average();
	~Average();

	//--------------
	void update(int);
	double get_avg_stream();
	double get_avg_real();
	void add_new_value(int);

	void calculate_real();
};