
enum ErrorCode {
	ILLEGAL_ARGUMENT = 0,
	INVALID_IPADDR = 1,
	WINSOCK_FAILED = 2,
	INVALID_NUMERIC = 3,
	GENERATOR_FALIED = 4,
}

struct Calc {
	1: double plus;
	2: double minus;
	3: double multiplies;
	4: double divides;
}

exception SampleException {
	1: ErrorCode code;
	2: string reason;
}

service Sample {
	string hello(2: string value) throws(1: SampleException e);

	string ipaddr() throws(1: SampleException e);

	i32 random(2: i32 num) throws(1: SampleException e);

	string uuid() throws(1: SampleException e);

	Calc calculator(
		2: double num1, 
		3: double num2) throws(1: SampleException e);
}