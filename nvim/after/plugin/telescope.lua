local builtin = require('telescope.builtin')
vim.keymap.set('n', '<leader>b', builtin.find_files, {})
vim.keymap.set('n', '<leader>g', builtin.git_files, {})
vim.keymap.set('n', '<leader>pg', function()
	builtin.grep_string({ search = vim.fn.input("Grep > ") })
end)

-- vim.keymap.set('n', '<leader>fh', builtin.help_tags, {})
