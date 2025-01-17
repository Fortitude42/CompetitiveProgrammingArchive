struct node {
	ll val, prior, sum, cnt;
	node *l, *r;
	node () {}
	node (ll v, ll p) {
		val = sum = v;
		prior = p;
		cnt = 1;
		l = r = NULL;	
	}	
};

typedef node * pnode;

ll cnt (pnode t) {
	return ((!t) ? 0: t->cnt);
}

ll sum (pnode t) {
	return ((!t) ? 0 : t->sum);
}


void upd (pnode &t) {
	if (!t)
		return;
	t->cnt = 1 + cnt(t->r) + cnt(t->l); 
	t->sum = t->val;
	t->sum += sum(t->l);
	t->sum += sum(t->r);
}

void split (pnode t, ll key, pnode &l, pnode &r, ll add = 0) {
	if (!t) {
		l = r = NULL;
		return;
	}

	ll cur_key = cnt(t->l) + add;	
	if (key <= cur_key) {
		split(t->l, key, l, t->l, add);
		r = t;
	} else {
		split(t->r, key, t->r, r, cur_key + 1);
		l = t;
	}
	upd(t);
}


void merge (pnode &t, pnode l, pnode r) {
	if (!l)
		t = r;
	else if (!r)
		t = l;
	else if (l->prior > r->prior) {
		merge(l->r, l->r, r);
		t = l;
	} else {
		merge(r->l, l, r->l);
		t = r;
	}
	upd(t);
}

pnode root[maxn];
pnode A, B, C;  

void out (pnode t) {
	if (!t)
		return;
	out(t->l);
	cout << t->val << ' ';
	out(t->r);
}

void update (ll lvl, ll pos, ll x) {
	split(root[lvl], pos, A, B);
	split(A, pos - 1, C, A);
	add(A->val, x);
	merge(root[lvl], C, A);
	merge(root[lvl], root[lvl], B);	
}


ll get (ll lvl, ll r) {
	split(root[lvl], r, A, B);
	ll ans = sum(A);
	merge(root[lvl], A, B);
	return ans;
}
