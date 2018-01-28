Node* Reverse(Node* head)
{
	Node* curr, *prev, *next;
	if (head == NULL) return NULL;
	curr = head;
	prev = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		curr->prev = next;
		prev = curr;
		curr = next;
	}
	head = prev;
	return head;
}
