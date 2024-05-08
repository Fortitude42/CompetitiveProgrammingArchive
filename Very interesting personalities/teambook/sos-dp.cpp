for (int i = 0; i < n; ++i)
	for (int mask = 0; mask < (1 << n); ++mask)
		if (mask & (1 << i))
			dp[mask] += dp[mask ^ (1 << i)];