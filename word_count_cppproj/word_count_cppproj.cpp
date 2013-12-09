// word_count_cppproj.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "open_file.h"
#include "TextQuery.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace::std;

// �����������1, ĩβ��s
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
	// ÿ�����ʳ��ֵ��д�ӡһ��
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
		cout << "����һ����Ҫ��ѯ��word, ��q�˳�:" << endl;
		string s;


		// �����˳�����
		if(!cin || s == "q") break;
		// ��ȡһ������ĳ����е�set
		set<TextQuery::line_no> locs = tq.run_query(s);
		// ��ӡ���
		print_results(locs, s, tq);
	}
	

	return 0;
}