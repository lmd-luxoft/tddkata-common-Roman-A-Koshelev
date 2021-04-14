#include "pch.h"
#include "Calc.h"
#include <charconv>
#include<string_view>

static const int ERR_CODE_SUCCESS = 0;
static const int ERR_CODE_FAILD = -1;

Calc::Calc() {
}

Calc::~Calc() {
}

int parse_str(
		std::string_view str
		, std::string_view& val1
		, std::string_view& val2) {
	static constexpr size_t comma_len = 1;
	static constexpr char comma = ',';
	size_t pos;
	size_t val_count;

	if (str.empty()) {
		val_count = 0;
		return val_count;
	}

	// Находим разделитель
	pos = str.find(comma);
	if (std::string_view::npos == pos) {
		val_count = 1;
		val1 = str;
		return val_count;
	}

	val_count = 2;
	val1 = str.substr(0, pos);
	val2 = str.substr(pos + 1);
	return val_count;
}

int Calc::sum(std::string expr) {
	static constexpr char dot = '.';
	std::string_view val1;
	std::string_view val2;
	std::int64_t v1 = 0;
	std::int64_t v2 = 0;

	int err_code = parse_str(expr, val1, val2);

	int val_count = err_code;
	if (0 < val_count) {
		if (std::string_view::npos != val1.find(dot)) {
			return ERR_CODE_FAILD;
		}
		if (auto [p, ec] = std::from_chars(val1.data(), val1.data() + val1.length(), v1);
			ec != std::errc()) {
			return ERR_CODE_FAILD;
		}
		if (v1 < 0) {
			return ERR_CODE_FAILD;
		}
	}

	if (1 < val_count) {
		if (std::string_view::npos != val2.find(dot)) {
			return ERR_CODE_FAILD;
		}
		if (auto [p, ec] = std::from_chars(val2.data(), val2.data() + val2.length(), v2);
			ec != std::errc()) {
			return ERR_CODE_FAILD;
		}
		if (v2 < 0) {
			return ERR_CODE_FAILD;
		}
	}

	if (std::numeric_limits<int>::max() < v1
			|| std::numeric_limits<int>::max() < v2
			|| std::numeric_limits<int>::max() < v1 + v2) {
		return ERR_CODE_FAILD;
	}

	return (int)(v1 + v2);
}
