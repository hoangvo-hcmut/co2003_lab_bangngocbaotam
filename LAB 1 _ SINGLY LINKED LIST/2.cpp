void Polynomial::insertTerm(const Term &term)
{
if (term.coeff == 0) return;
  int i = 0;
  while (i < this->terms->size() && this->terms->get(i).exp > term.exp)
  {
    i += 1;
  }
  if (i < this->terms->size() && this->terms->get(i).exp == term.exp)
  {
      int coeff = term.coeff + this->terms->get(i).coeff;
      if (coeff != 0) this->terms->set(i, Term(coeff, term.exp));
      else this->terms->removeAt(i);
  }
  else
  {
    this->terms->add(i, Term(term.coeff, term.exp));
  }
}

void Polynomial::insertTerm(double coeff, int exp)
{
  this->insertTerm(Term(coeff, exp));
}
