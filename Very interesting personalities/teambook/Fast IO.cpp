//https://oj.uz/submission/202009
inline int R () {
	char c;
	bool is_negative = 0, started = 0;
	int ans = 0;
	while (1) {
		c = getchar();
		if ((c > '9' || c < '0') && c != '-' && !started)
			continue;
		if ((c > '9' || c < '0') && c != '-' && started)
			break;
		started = 1;
		if (c == '-')
			is_negative = 1;
		else
			ans = ans * 10 + c - '0';
	}
 
	return ans;
}
