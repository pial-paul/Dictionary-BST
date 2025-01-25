 <header>
        <h1>Dictionary Using Binary Search Tree (BST)</h1>
    </header>

    <section>
        <h2>Overview</h2>
        <p>This project implements a <strong>digital dictionary</strong> using the Binary Search Tree (BST) data structure. It allows users to efficiently <strong>insert</strong>, <strong>delete</strong>, <strong>search</strong>, and <strong>display words</strong> along with their meanings in alphabetical order.</p>
    </section>

    <section>
        <h2>Features</h2>
        <ul>
            <li><strong>Insert Words:</strong> Add new words with meanings while avoiding duplicates.</li>
            <li><strong>Delete Words:</strong> Remove words with proper handling for leaf, single-child, and two-child nodes.</li>
            <li><strong>Search Words:</strong> Find a word and display its meaning, or notify if it doesn’t exist.</li>
            <li><strong>Display Dictionary:</strong> View all entries sorted alphabetically.</li>
        </ul>
    </section>

    <section>
        <h2>How to Use</h2>
        <ol>
            <li><strong>Clone the Repository:</strong>
                <pre><code>git clone https://github.com/&lt;your-username&gt;/dictionary-using-BST.git
cd dictionary-using-BST</code></pre>
            </li>
            <li><strong>Compile the Program:</strong>
                <pre><code>gcc dictionary.c -o dictionary</code></pre>
            </li>
            <li><strong>Run the Program:</strong>
                <pre><code>./dictionary</code></pre>
            </li>
            <li><strong>Interact Using the Menu:</strong>
                <ul>
                    <li>[1] Insert a word</li>
                    <li>[2] Delete a word</li>
                    <li>[3] Search for a word</li>
                    <li>[4] Display all words</li>
                    <li>[0] Exit</li>
                </ul>
            </li>
        </ol>
    </section>

    <section>
        <h2>Example</h2>
        <pre><code>
[1] INSERT
[2] DELETE
[3] SEARCH 
[4] DISPLAY WHOLE
[0] EXIT
        </code></pre>

        <h3>Sample Interaction:</h3>
        <pre><code>
ENTER YOUR CHOICE: 1
Word to insert: Apple
Meaning: A fruit.

ENTER YOUR CHOICE: 4
Word: Apple
Meaning: A fruit.
        </code></pre>
    </section>

    <section>
        <h2>Applications</h2>
        <ul>
            <li><strong>Efficient Data Management:</strong> Stores and retrieves words in alphabetical order.</li>
            <li><strong>Educational Tool:</strong> Demonstrates practical usage of Binary Search Trees in real-world scenarios.</li>
        </ul>
    </section>

    <section>
        <h2>Credits</h2>
        <p><strong>Developed By:</strong></p>
        <ul>
            <li>Pial Paul (ID: 22102022)</li>
            <li>Sayanti Choudhry (ID: 22102023)</li>
        </ul>
        <p><strong>Instructor:</strong> Habibur Rahaman, Lecturer, Department of Computer Science & Engineering, Chittagong Independent University.</p>
    </section>

    <section>
        <h2>License</h2>
        <p>This project is licensed under the MIT License. Feel free to contribute!</p>
    </section>
</body>
