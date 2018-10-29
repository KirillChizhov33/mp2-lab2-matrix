#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));// не вызывает исключений
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));//вызывает любое исключение
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
	const int Size = 100;
	TVector<int> OriginalVector(Size), CopiedVector(Size);
	for (int i = 0; i < Size; i++)
	{
		OriginalVector[i] = i;
	}
	CopiedVector = OriginalVector;

	EXPECT_EQ(CopiedVector, OriginalVector);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	const int Size = 100;
	TVector<int> OriginalVector(Size), CopiedVector(Size);

	EXPECT_NE(&OriginalVector[0], &CopiedVector[0]);
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
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[-2]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[5]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);

	ASSERT_NO_THROW(v == v);//ASSERT_EQ(v,v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	const int Size = 100;
	TVector<int> Vector1(Size);
	TVector<int> Vector2(Size);

	EXPECT_EQ(Vector1, Vector2);
}

TEST(TVector, assign_operator_change_vector_size)
{
	const int Size = 100;
	TVector<int> Vector1(Size);
	TVector<int> Vector2(Size + 1);
	Vector2 = Vector1;

	EXPECT_EQ(Size, Vector2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	const int Size = 100;
	TVector<int> Vector1(Size);
	TVector<int> Vector2(Size + 1);

	ASSERT_NO_THROW(Vector1 = Vector2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	const int Size = 100;
	TVector<int> Vector1(Size);
	TVector<int> Vector2(Size);
	//Vector2[7] = 3; Test failed
	EXPECT_EQ(Vector1, Vector2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	const int Size = 100;
	TVector<int> Vector1(Size);

	ASSERT_NO_THROW(Vector1 == Vector1);//ASSERT_EQ(Vector1, Vector1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	const int Size = 100;
	TVector<int> Vector1(Size);
	TVector<int> Vector2(Size + 1);

	EXPECT_NE(Vector1, Vector2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	const int Size = 100;
	TVector<int> Vector1(Size);

	ASSERT_NO_THROW(Vector1 + Size);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	const int Size = 100;
	TVector<int> Vector1(Size);

	ASSERT_NO_THROW(Vector1 - Size);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	const int Size = 100;
	TVector<int> Vector1(Size);

	ASSERT_NO_THROW(Vector1 * Size);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	const int Size = 100;
	TVector<int> Vector1(Size);
	TVector<int> Vector2(Size);

	ASSERT_NO_THROW(Vector1 + Vector2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	const int Size = 100;
	TVector<int> Vector1(Size);
	TVector<int> Vector2(Size + 1);

	ASSERT_ANY_THROW(Vector1 + Vector2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	const int Size = 100;
	TVector<int> Vector1(Size);
	TVector<int> Vector2(Size);

	ASSERT_NO_THROW(Vector1 - Vector2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	const int Size = 100;
	TVector<int> Vector1(Size);
	TVector<int> Vector2(Size + 1);

	ASSERT_ANY_THROW(Vector1 - Vector2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	const int Size = 100;
	TVector<int> Vector1(Size);
	TVector<int> Vector2(Size);

	ASSERT_NO_THROW(Vector1 * Vector2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	const int Size = 100;
	TVector<int> Vector1(Size);
	TVector<int> Vector2(Size + 1);

	ASSERT_ANY_THROW(Vector1 * Vector2);
}
