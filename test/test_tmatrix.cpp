#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(m);
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5), m1(m);
	EXPECT_EQ(true, &m != &m1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[1][2] = 3;
	EXPECT_EQ(3, m[1][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-1][-2] = 3);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[10][6] = 3);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
		m[i][i] = 1;
	EXPECT_EQ(m, m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5), m1(5);
	for (int i = 0; i < 5; i++)
		m[i][i] = 1;
	EXPECT_EQ(m, m1 = m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5), m1(6);
	m = m1;
	EXPECT_EQ(6, m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(5), m1(3), expm(5);
	for (int i = 0; i < 5; i++)
		m[i][i] = 1;
	for (int i = 0; i < 5; i++)
		expm[i][i] = 1;
	EXPECT_EQ(expm, m1 = m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(5), m2(5);
	m1[1][1] = 5;
	m2[1][1] = 5;

	ASSERT_TRUE(m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m1(5);
	m1[1][1] = 5;
	ASSERT_TRUE(m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(5), m2(6);
	m1[1][1] = 5;
	m2[1][1] = 5;
	ASSERT_FALSE(m1 == m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(3);
	m1[0][0] = 2;
	m1[0][2] = 7;
	m1[1][1] = 1;
	m1[1][2] = -8;
	m1[2][2] = -2;
	TMatrix<int> m2(3);
	m2[0][1] = 3;
	m2[0][2] = -7;
	m2[1][1] = 4;
	m2[1][2] = 5;
	m2[2][2] = 2;
	TMatrix<int> expm(3);
	expm[0][0] = 2;
	expm[0][1] = 3;
	expm[1][1] = 5;
	expm[1][2] = -3;
	EXPECT_EQ(expm, m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(5), m2(6);
	m1[4][4] = 2;
	m2[4][4] = 3;
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(3);
	m1[0][0] = 2;
	m1[0][2] = 7;
	m1[1][1] = 1;
	m1[1][2] = -8;
	m1[2][2] = -2;
	TMatrix<int> m2(3);
	m2[0][1] = 3;
	m2[0][2] = 7;
	m2[1][1] = 4;
	m2[1][2] = 5;
	m2[2][2] = -2;
	TMatrix<int> expm(3);
	expm[0][0] = 2;
	expm[0][1] = -3;
	expm[1][1] = -3;
	expm[1][2] = -13;
	EXPECT_EQ(expm, m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(5), m2(6);
	m1[4][4] = 2;
	m2[4][4] = 3;
	ASSERT_ANY_THROW(m1 - m2);
}

TEST(TMatrix, can_set_one_matrix)
{
	TMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
		m[i][i] = 1;
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(1, m[i][i]);
}