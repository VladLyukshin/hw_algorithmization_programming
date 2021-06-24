#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string>
#include <eigen-master/Eigen/Eigen> 
#include <eigen-master/Eigen/Dense>
#include <eigen-master/Eigen/IterativeLinearSolvers>
#include <fast-cpp-csv-parser-master/csv.h>
using namespace std;

typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MatrixXd;

void removeColumn(Eigen::MatrixXd& matrix, unsigned int colToRemove)
{
	unsigned int numRows = matrix.rows();
	unsigned int numCols = matrix.cols() - 1;

	if (colToRemove < numCols)
		matrix.block(0, colToRemove, numRows, numCols - colToRemove) = matrix.block(0, colToRemove + 1, numRows, numCols - colToRemove);

	matrix.conservativeResize(numRows, numCols);
}

template <std::size_t... Idx, typename T, typename R>
bool read_row_help(std::index_sequence<Idx...>, T& row, R& r) {
	return r.read_row(std::get<Idx>(row)...);
}

template <std::size_t... Idx, typename T>
void fill_values(std::index_sequence<Idx...>,
	T& row,
	std::vector<double>& data) {
	data.insert(data.end(), { std::get<Idx>(row)... });
}

int main(int argc, char** argv) {

	auto file_path = "housing.csv";
	const uint32_t columns_num = 10;
	io::CSVReader<columns_num> csv_reader(file_path);
	const double eps = 10; 
	const double mu = 2;

	std::vector<std::string> categorical_column;
	std::vector<double> values;
	using RowType = std::tuple<double, double, double, double, double, double, double, double, double, std::string>;
	RowType row;
	csv_reader.read_header(0, "longitude", "latitude", "housing_median_age", "total_rooms", "total_bedrooms", "population", "households",
		"median_income", "median_house_value", "ocean_proximity");


	int rows_num = 0;
	try {
		bool done = false;
		while (!done) {
			done = !read_row_help(
				std::make_index_sequence<std::tuple_size<RowType>::value>{}, row,
				csv_reader);
			if (!done) {
				categorical_column.push_back(std::get<9>(row));
				fill_values(std::make_index_sequence<columns_num - 1>{}, row, values);
				++rows_num;
			}
		}
	}
	catch (const io::error::no_digit& err) {
		// ignore bad formated samples
		std::cerr << err.what() << std::endl;
	}


	//  Convert Data into Eigen Matrix
	auto x_data = Eigen::Map<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>>(
		values.data(), rows_num, columns_num - 1);

	Eigen::Matrix<double, Eigen::Dynamic,
		Eigen::Dynamic> Y_target(rows_num, 1);

	Y_target = x_data.col(8);	

	//  Choose normalization (look comments below after the main program)

	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> x_data_min_max =
	          (x_data.rowwise() - x_data.colwise().minCoeff()).array().rowwise() /
	          (x_data.colwise().maxCoeff() - x_data.colwise().minCoeff()).array();

		

	//    Set sizes of your train and test data
	int test_size = 4128; // выбираем 80/20 пропорцию для train/test
	int train_size = rows_num - test_size;

	//    Select Data for training and testing (use block method from Eigen)
		// For example, x_data.block(train_size,8,test_size,1) 

	auto data = x_data_min_max.block(0, 2, train_size, 6); 
	auto y = Y_target.block(0, 0, train_size, 1);

	auto testing_x = x_data_min_max.block(train_size, 2, test_size, 6);
	auto test_y = Y_target.block(train_size, 0, test_size, 1);

	//    Implement Gradiend Descend Method, find vector b

	Eigen::Matrix<double, Eigen::Dynamic,
		Eigen::Dynamic> w(6, 1); 

	for (int i = 0; i < 6; i++) // начальное значение вектора весов 
	{
		w(i, 0) = 0;
	}
	int count = 0;
	while ((((double)2 / train_size) * data.transpose() * (data * w - y)).norm() >= eps)
	{
		count++;
		w -= mu * (((double)2 / train_size) * data.transpose() * (data * w - y));
		if (count % 50 == 0)
		{
			cout << "ITERATION - " << count << endl;
			cout << (((double)2 / train_size) * data.transpose() * (data * w - y)).norm() << endl;
		}
	}

	//    Calculate prediction

	auto predicted_y = testing_x * w;

	//   Calculate  Mean Squared Error
	auto MSE = (test_y - predicted_y).transpose() * (test_y - predicted_y);
	std::cout << std::endl << "Mean square error = " << MSE / test_size;


	//    Min-Max normalization
		  // Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> x_data_min_max =
		  //     (x_data.rowwise() - x_data.colwise().minCoeff()).array().rowwise() /
		  //     (x_data.colwise().maxCoeff() - x_data.colwise().minCoeff()).array();

	//
	//      // Feature-scaling(Normalization):
	//      // Standardization - zero mean + 1 std
	//      Eigen::Array<double, 1, Eigen::Dynamic> std_dev =
	//          ((x_data.rowwise() - x_data.colwise().mean())
	//               .array()
	//               .square()
	//               .colwise()
	//               .sum() /
	//           (x_data.rows() - 1))
	//              .sqrt();
	//
	//      Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> x_data_std =
	//          (x_data.rowwise() - x_data.colwise().mean()).array().rowwise() /
	//          std_dev;
	//
	//      std::cout << x_data_std << std::endl;

	//      // Min-Max normalization
	//      Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> x_data_min_max =
	//          (x_data.rowwise() - x_data.colwise().minCoeff()).array().rowwise() /
	//          (x_data.colwise().maxCoeff() - x_data.colwise().minCoeff()).array();
	//
	//      std::cout << x_data_min_max << std::endl;

	//      // Average normalization
	//      Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> x_data_avg =
	//          (x_data.rowwise() - x_data.colwise().mean()).array().rowwise() /
	//          (x_data.colwise().maxCoeff() - x_data.colwise().minCoeff()).array();
	//
	//      std::cout << x_data_avg << std::endl;




	return 0;
}