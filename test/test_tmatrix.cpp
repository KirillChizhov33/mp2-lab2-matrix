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
	const int Size = 100;
	TMatrix<int> OriginalMatrix(Size), CopiedMatrix(Size);
	for (int i = 0; i < Size; i++)
	{
		OriginalMatrix[i] = i;
	}
	CopiedMatrix = OriginalMatrix;

	EXPECT_EQ(CopiedMatrix, OriginalMatrix);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	const int Size = 100;
	TMatrix<int> OriginalMatrix(Size), CopiedMatrix(Size);

	EXPECT_NE(&OriginalMatrix[0], &CopiedMatrix[0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> v(4);
	v[0] = TVector<int>(5, 2);

	EXPECT_EQ(TVector<int>(5, 2), v[0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> v(4);

	ASSERT_ANY_THROW(v[-2]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> v(4);

	ASSERT_ANY_THROW(v[MAX_MATRIX_SIZE + 1]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> v(4);

	ASSERT_NO_THROW(v == v);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	const int Size = 100;
	TMatrix<int> Matrix1(Size);
	TMatrix<int> Matrix2(Size);

	EXPECT_EQ(Matrix1, Matrix2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	const int Size = 100;
	TMatrix<int> Matrix1(Size);
	TMatrix<int> Matrix2(Size + 1);
	Matrix2 = Matrix1;

	EXPECT_EQ(Size, Matrix2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	const int Size = 100;
	TMatrix<int> Matrix1(Size);
	TMatrix<int> Matrix2(Size + 1);

	ASSERT_NO_THROW(Matrix1 = Matrix2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	const int Size = 100;
	TMatrix<int> Matrix1(Size);
	TMatrix<int> Matrix2(Size);

	EXPECT_EQ(Matrix1, Matrix2);
}


TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	const int Size = 100;
	TMatrix<int> Matrix1(Size);

	ASSERT_NO_THROW(Matrix1 == Matrix1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	const int Size = 100;
	TMatrix<int> Matrix1(Size);
	TMatrix<int> Matrix2(Size + 1);

	EXPECT_NE(Matrix1, Matrix2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	const int Size = 10;
	TMatrix<int> Matrix1(Size);
	TMatrix<int> Matrix2(Size);

	ASSERT_NO_THROW(Matrix1 + Matrix2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	const int Size = 100;
	TMatrix<int> Matrix1(Size);
	TMatrix<int> Matrix2(Size + 1);

	ASSERT_ANY_THROW(Matrix1 + Matrix2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	const int Size = 100;
	TMatrix<int> Matrix1(Size);
	TMatrix<int> Matrix2(Size);

	ASSERT_NO_THROW(Matrix1 - Matrix2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	const int Size = 100;
	TMatrix<int> Matrix1(Size);
	TMatrix<int> Matrix2(Size + 1);

	ASSERT_ANY_THROW(Matrix1 - Matrix2);
}


