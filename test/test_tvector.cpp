#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(7);
	v[1] = 3;
	TVector<int> v1(v);
	EXPECT_EQ(v1, v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(7), v1(v);
	EXPECT_EQ(true, &v != &v1);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(7);
	ASSERT_ANY_THROW(v[-1] = 1);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(7);
	ASSERT_ANY_THROW(v[8] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(7);
	for (int i = 0; i < 7; i++)
		v[i] = 1;
	EXPECT_EQ(v, v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(7), v1(7);
	for (int i = 0; i < 7; i++)
		v[i] = 1;
	EXPECT_EQ(v, v1 = v);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(7), v1(8);
	v = v1;
	EXPECT_EQ(v1.GetSize(), v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(7), v1(8);
	v = v1;
	EXPECT_EQ(v1, v);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(7), v1(7);
	v[1] = 7;
	v1[1] = 7;
	ASSERT_TRUE(v == v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(7);
	v[1] = 7;
	ASSERT_TRUE(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(7), v1(8);
	v[1] = 7;
	v1[1] = 7;
	ASSERT_FALSE(v == v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(3), v1(3);
	v[1] = 3;
	v = v + 2;
	v1[0] = 2;
	v1[1] = 5;
	v1[2] = 2;
	EXPECT_EQ(v1, v);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(3), expv(3);
	v[1] = 3;
	v = v - 2;
	expv[0] = -2;
	expv[1] = 1;
	expv[2] = -2;
	EXPECT_EQ(expv, v);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(3), v1(3);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v = v * 2;
	v1[0] = 2;
	v1[1] = 4;
	v1[2] = 6;
	EXPECT_EQ(v1, v);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(3), v2(3), v3(3);
	v1[0] = 2;
	v1[1] = 7;
	v2[1] = 4;
	v3[0] = 2;
	v3[1] = 11;
	EXPECT_EQ(v3, v1 + v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(3), v2(4);
	v1[1] = 4;
	v2[1] = 6;
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<double> v1(3), v2(3), v3(3);
	v1[0] = 1;
	v1[1] = 7;
	v2[1] = 4;
	v3[0] = 1;
	v3[1] = 3;
	EXPECT_EQ(v3, v1 - v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(3), v2(4);
	v1[1] = 4;
	v2[1] = 6;
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(3), v2(3);
	int v3 = 25;
	v1[0] = 5;
	v1[1] = 1;
	v2[0] = 3;
	v2[1] = 10;
	EXPECT_EQ(v3, v1 * v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<double> v1(3), v2(4);
	v1[1] = 4;
	v2[1] = 6;
	ASSERT_ANY_THROW(v1 * v2);
}

TEST(TVector, can_multiply_zero)
{
	TVector<int> v1(2);
	v1[1] = 10;
	v1[0] = 8;
	v1 = v1 * 0;
	EXPECT_EQ(0,v1[1]+v1[0]);
}

TEST(TVector, double_sum_is_multiply_vector_on_vector)
{
	TVector<int> v1(2), v2(2);
	v1[0] = 2;
	v1[1] = 4;
	v2 = v1 + v1;
	EXPECT_EQ(12, v2[0] + v2[1]);
}

TEST(TVector, sum_two_zerovectors_is_zero)
{
	TVector<int> v1(2), v2(2), v3(2);
	v1[0] = 0;
	v1[1] = 0;
	v2[0] = 0;
	v2[1] = 0;
	v3 = v1 + v2;
	EXPECT_EQ(0, v3[0] + v3[1]);
}

TEST(TVector, can_eq_elemvector_to_var)
{
	TVector<int> v1(2);
	int a = 10;
	int b = 100;
	v1[0] = a;
	v1[1] = b;
	EXPECT_EQ(10, v1[0]);
	EXPECT_EQ(100, v1[1]);
}


TEST(TVector, multiple_to_one_is_our_vector)
{
	TVector<int> v1(2), v2(2);
	int a = 1;
	v1[0] = 5;
	v1[1] = 10;
	v2 = v1*a;
	EXPECT_EQ(v2,v1);
}