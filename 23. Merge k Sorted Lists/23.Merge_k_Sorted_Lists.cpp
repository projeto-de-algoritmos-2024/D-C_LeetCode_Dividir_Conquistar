class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Comparador
        auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        // Fila de prioridade
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        // Adiciona o inicio de cada lista na fila de prioridade
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        // Nó auxiliar para iniciar a lista mesclada
        ListNode* aux = new ListNode();
        ListNode* current = aux;

        // Mesclar as listas
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            current->next = smallest;
            current = current->next;

            if (smallest->next) {
                pq.push(smallest->next);
            }
        }