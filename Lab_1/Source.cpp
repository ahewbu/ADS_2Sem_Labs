﻿#include <iostream>
#include <chrono>
#include <exception>
#include "Set.h"

#include <vector>


//using namespace std;
//
//struct steady_clock;



//int main()
//{
//    vector<int> v;
//    v.push_back(1);
//    v.push_back(4);
//    v.push_back(3);
//    v.push_back(4);
//    v.push_back(4);
//    v.push_back(3);
//    v.push_back(3);
//    v.push_back(2);
//    v.push_back(1);
//    for (int i = 0; i < v.size(); ++i) {
//       cout << v[i] << " " << endl;
//    }
//    cout << "==================" << endl;
//    v = NotRepeatElems(v);
//    for (int i = 0; i < v.size(); ++i) {
//        cout << v[i] << " " << endl;
//    }

//	Set r;
//	r.Insert(1);
//	r.Insert(6);
//	r.Insert(7);
//	r.Insert(5);
//	r.Insert(-6);
//	r.Print();
//	cout << endl << "==================" << endl;
//	cout << r.Find(15) << endl;
//	cout << r.Find(6) << endl;
//	cout << "==================" << endl;
//	r.Erase(7);
//	r.Erase(15);
//	r.Print();

//    Set r;
//	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//	for (int i = 0; i < 100; i++)
//	{
//		begin = std::chrono::steady_clock::now();
//		for (int j = 1; j < 1000; j++)
//		{
//			r.Insert(i * 1000 + j);
//		}
//        end = std::chrono::steady_clock::now();
//		std::cout << "Diff(ms) = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
//	}
//
//	std::cout << "Diff(mcs) = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
//	std::cout << "Diff(ns) = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << std::endl;
//	return 0;
//}