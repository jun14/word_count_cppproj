#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <map>

using namespace std;

class TextQuery
{
public:
	typedef vector<string>::size_type line_no;
	/* �ӿ�˵��
	 *		read_file Ϊ�����ļ��������ݽṹ
	 *		run_query ����ָ����,������һ��set�������������ֵ���
	 *		text_line ���������ļ���ָ����һ��
	 */
	void read_file(ifstream &is)
	{ store_file(is); build_map(); }
	set<line_no> run_query(const string& ) const;
	string text_line(line_no) const;
private:
	void store_file(ifstream &); //����input file
	void build_map(); // Ϊÿ����������������ֵ���,��set����
	// ��¼���������ļ�
	vector<string> lines_of_text;
	// ��¼�����Լ����ǳ��ֵ�������
	map<string, set<line_no>> word_map;
};




#endif