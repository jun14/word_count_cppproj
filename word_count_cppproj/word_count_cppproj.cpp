// word_count_cppproj.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "open_file.h"
#include "TextQuery.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace::std;

// 如果数量大于1, 末尾加s
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1)? word : word + ending;
}

void print_results(const set<TextQuery::line_no>& locs, 
				const string & sought, const TextQuery &file)
{
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout<<"\n"<<sought<<" occurs "
		<<size<<" "
		<<make_plural(size, "time", "s") << endl;
	// 每个单词出现的行打印一行
	line_nums::const_iterator it = locs.begin();
	for (; it != locs.end(); ++it)
	{
		cout << "\t(line "
			 << (*it) + 1 << ") "
			 << file.text_line(*it) << endl;
	}

}

int _tmain(int argc, char* argv[])
{
	ifstream infile;
	if(argc < 2 || !open_file(infile, argv[1]) )
	{
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	TextQuery tq;
	tq.read_file(infile);

	while(1)
	{
		cout << "输入一个想要查询的word, 按q退出:" << endl;
		string s;


		// 程序退出条件
		if(!cin || s == "q") break;
		// 获取一个词语的出现行的set
		set<TextQuery::line_no> locs = tq.run_query(s);
		// 打印结果
		print_results(locs, s, tq);
	}
	

	return 0;
}