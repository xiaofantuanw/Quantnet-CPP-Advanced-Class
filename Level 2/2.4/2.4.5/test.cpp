//test.cpp
//Author: TengxiaoFan
//This file will test the file deleter and shared ptr
#include <iostream>
#include <memory>

class FileFinalizer
{
	//Function object for file deleter
public:
	void operator() (FILE* fp)
	{
		fclose(fp);
		std::cout << "File Closed by function object" << std::endl;
	}
};

void FileFinalizer2(FILE* fp)
{//Free function for file deleter
	fclose(fp);
	std::cout << "File Closed by free function" << std::endl;
}

int main()
{
	//Three files for test
	FILE* myFile1;
	fopen_s(&myFile1,"text1.txt", "w");
	FILE* myFile2;
	fopen_s(&myFile2, "text2.txt", "w");
	FILE* myFile3;
	fopen_s(&myFile3, "text3.txt", "w");


	//Test the three kinds of file finalizers
	FileFinalizer FileFinalizer1;//Function Object
	auto FileFinalizer3 = [](FILE * fp)//Lambda function for file deleter
	{
		fclose(fp);
		std::cout << "File Closed by lambda function" << std::endl;
	};
	std::shared_ptr<FILE> mySharedFile1(myFile1, FileFinalizer1);
	std::shared_ptr<FILE> mySharedFile2(myFile2,FileFinalizer2);
	std::shared_ptr<FILE> mySharedFile3(myFile3, FileFinalizer3);
	//All the three files are closed

	/*
	//In this block, the file cannot be closed and we'll have no access to it
	try
	{
		FILE* myFile;
		fopen_s(&myFile, "text.txt", "w");
		throw - 1;
		fclose(myFile);
	}
	catch (int i)
	{
		std::cout << "err " << i << " caught." << std::endl;
	}
	*/
	

	//try to write sth in file1
	try
	{
		for (int i = 1;i < 10;i++)
		{
			fprintf(mySharedFile1.get(), "%d ", i);
			if (i == 5)
				throw 5;
		}
	}
	catch (int i)
	{
		std::cout << "err " << i << " caught." << std::endl;
		fopen_s(&myFile1, "text1.txt", "w");
	}
}