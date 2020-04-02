// 
//
//  Lab# 10, Calculate the average streaming
//
//  Created by Mohammed Shehab on 4/1/2020.
//  Copyright © 2020 Mohammed Shehab. All rights reserved.
//
#include "Average.h"

Average::Average()
{
	this->ave_stream = this->ave_real = 0.0;
	this->count = 0;
	
}

Average::~Average()
{
	all_data.clear();
}

void Average::update(int v)
{
	// Sec
	double d_v = double(v);
	this->count++;
	double differential = (d_v - this->ave_stream) / double(this->count);
	double newMean = this->ave_stream + differential;
	this->ave_stream = newMean;
	// Add this new income value to data list
	this->add_new_value(v);
}

double Average::get_avg_stream()
{
	return this->ave_stream;
}

double Average::get_avg_real()
{
	return this->ave_real;
}

void Average::add_new_value(int v)
{
	all_data.push_back(v);
}

void Average::calculate_real()
{
	int count = all_data.size();
	double sum = 0.0;

	for (int i : all_data)
	{
		sum += double(i);
	}
	this->ave_real = sum / double(count);
}
