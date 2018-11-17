#include "postfix.h"
#include <gtest.h>
#include <string>
//
TEST(TPostfix, can_create_postfix)
{
	string tmp = "5+5";
	//TPostfix p(tmp);
	ASSERT_NO_THROW(TPostfix p(tmp));
}

TEST(TPostfix, cant_create_postfix_with_incorrectinfix)
{
	string tmp = "5+5-";
	ASSERT_ANY_THROW(TPostfix p(tmp));
}

//TEST(TPostfix, IsCorrectlyInxix_true)
//{
//	string tmp = "5+5*(12/6+0.5)";
//	TPostfix p(tmp);
//	EXPECT_EQ(true, p.IsCorrectInfix(tmp));
//}
//
//TEST(TPostfix, IsCorrectlyInxix_false)
//{
//	string tmp = "5+5*(12/6+0.5)";
//	TPostfix p(tmp);
//	tmp += '-';
//	EXPECT_EQ(false, p.IsCorrectInfix(tmp));
//}
//
//TEST(TPostfix, Priority)
//{
//	string tmp = "5+5";
//	TPostfix p(tmp);
//	bool flag = false;
//	if (p.Priority('(') == 0 && p.Priority(')') == 1 && p.Priority('+') == 2 && p.Priority('-') == 2
//		&& p.Priority('*') == 3 && p.Priority('/') == 3)
//		flag = true;
//	EXPECT_EQ(true, flag);
//}
//
//TEST(TPostfix, IsOperation)
//{
//	string tmp = "5+5";
//	TPostfix p(tmp);
//	EXPECT_EQ(true, (p.IsOperation('+') || p.IsOperation('-') || p.IsOperation('*') || p.IsOperation('/')));
//}
//
//TEST(TPostfix, not_IsOperation)
//{
//	string tmp = "5+5";
//	TPostfix p(tmp);
//	EXPECT_EQ(false, p.IsOperation('6'));
//}
//
//TEST(TPostfix, IsOperand)
//{
//	string tmp = "5+5";
//	TPostfix p(tmp);
//	bool flag = true;
//	for(char i='0';i<='9';i++)
//		if (!p.IsOperand(i))
//		{
//			flag = false;
//			break;
//		}
//	EXPECT_EQ(true, flag);
//}
//
//TEST(TPostfix, not_IsOperand)
//{
//	string tmp = "5+5";
//	TPostfix p(tmp);
//	EXPECT_EQ(false, p.IsOperand('-'));
//}
//
//TEST(TPostfix, ToPostfix)
//{
//	string tmp = "(1+2)*(1-3/3*6-4)";
//	TPostfix p(tmp);
//	tmp = "1 2 + 1 3 3 / 6 * - 4 - * ";
//	EXPECT_EQ(tmp, p.GetPostfix());
//}

TEST(TPostfix, Calculate)
{
    string tmp = "(1+2)*(1-3/3*6-4)";
	TPostfix p(tmp);
    EXPECT_EQ(-27,p.Calculate());
}
